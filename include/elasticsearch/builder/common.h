#pragma once

#include <elasticsearch/except.h>

#include <ext/pool>
#include <ext/string.h>
#include <http/http>
#include <nlohmann/json.hpp>
#include <timber/timber>

namespace elastic {
    using json = nlohmann::json;
}

namespace elastic::builder {
    struct request_bundle {
        http::client& client;
        ext::pool_item<http::request> request;
    };

    template <typename Derived>
    class common {
        http::client& client;
    protected:
        ext::pool_item<http::request> request;

        constexpr auto derived() -> Derived& {
            return *static_cast<Derived*>(this);
        }

        auto perform() -> ext::task<http::response> {
            const auto response = co_await this->request->perform(this->client);

            if (response.ok()) co_return response;

            throw es_error(response.status(), response.body());
        }
    public:
        common(request_bundle&& bundle) :
            client(bundle.client),
            request(std::move(bundle.request))
        {}

        common(const common&) = delete;

        common& operator=(const common&) = delete;

        ~common() {
            try {
                request->url().clear(CURLUPART_QUERY);
            }
            catch (const http::client_error& ex) {
                TIMBER_ERROR("could not clear request query: {}", ex.what());
            }
        }

        auto filter_path(
            std::initializer_list<std::string_view> filters
        ) -> Derived& {
            request->url().append_query(__FUNCTION__, ext::join(filters, ","));
            return derived();
        }
    };

    template <typename Derived>
    struct void_return : common<Derived> {
        using common<Derived>::common;

        auto send() -> ext::task<> {
            co_await this->perform();
        }
    };

    template <typename Derived>
    struct has_return : common<Derived> {
        using common<Derived>::common;

        auto send() -> ext::task<json> {
            const auto response = co_await this->perform();
            co_return json::parse(response.body());
        }
    };

    template <typename Derived>
    struct exists : void_return<Derived> {
        exists(request_bundle&& bundle) :
            void_return<Derived>(std::forward<request_bundle>(bundle))
        {
            this->request->method(http::method::HEAD);
        }

        auto send() -> ext::task<bool> {
            try {
                co_await void_return<Derived>::send();
                co_return true;
            }
            catch (const es_error& ex) {
                if (ex.status() == 404) co_return false;
                throw ex;
            }
        }
    };
}
