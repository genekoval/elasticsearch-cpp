#pragma once

#include <elasticsearch/except.h>

#include <ext/string.h>
#include <http/http>
#include <simdjson.h>
#include <timber/timber>

namespace elastic {
    using json = simdjson::ondemand::document_reference;
}

namespace elastic::builder {
    struct request_bundle {
        http::request* const request;
        http::memory* const memory;
        simdjson::ondemand::parser* const parser;
        simdjson::ondemand::document* const document;
    };

    template <typename Derived>
    class common {
    protected:
        request_bundle bundle;

        constexpr auto derived() -> Derived& {
            return *static_cast<Derived*>(this);
        }

        auto request() -> http::request& {
            return *this->bundle.request;
        }
    public:
        common(request_bundle&& bundle) : bundle(std::move(bundle)) {}

        common(const common&) = delete;

        common& operator=(const common&) = delete;

        ~common() {
            try {
                request().url().clear(CURLUPART_QUERY);
            }
            catch (const http::client_error& ex) {
                TIMBER_ERROR("could not clear request query: {}", ex.what());
            }
        }

        auto filter_path(
            std::initializer_list<std::string_view> filters
        ) -> Derived& {
            request().url().append_query(__FUNCTION__, ext::join(filters, ","));
            return derived();
        }
    };

    template <typename Derived>
    struct void_return : common<Derived> {
        using common<Derived>::common;

        auto send() -> void {
            auto& memory = *this->bundle.memory;

            auto response = this->request().perform(memory);

            if (response.ok()) return;

            throw es_error(response.status(), memory.storage);
        }
    };

    template <typename Derived>
    struct has_return : void_return<Derived> {
        using void_return<Derived>::void_return;

        auto send() -> json {
            void_return<Derived>::send();

            const auto& storage = this->bundle.memory->storage;
            auto& parser = *this->bundle.parser;

            *this->bundle.document = parser.iterate(storage);

            return *this->bundle.document;
        }
    };

    template <typename Derived>
    struct exists : void_return<Derived> {
        exists(
            request_bundle&& bundle
        ) :
            void_return<Derived>(std::move(bundle))
        {
            this->request().method(http::method::HEAD);
        }

        auto send() -> bool {
            try {
                void_return<Derived>::send();
                return true;
            }
            catch (const es_error& ex) {
                if (ex.status() == 404) return false;
                throw ex;
            }
        }
    };
}
