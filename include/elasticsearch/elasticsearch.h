#pragma once

#include "except.h"

#include <http/http>
#include <simdjson.h>

namespace elastic {
    using json = simdjson::ondemand::document_reference;

    class elasticsearch {
        const std::string host;
        const std::string auth;

        http::memory memory = { .padding = simdjson::SIMDJSON_PADDING };
        simdjson::ondemand::parser parser;
        simdjson::ondemand::document document;

        auto get(http::request& req) -> json;

        template <typename ...Args>
        auto request(
            std::string_view path_string,
            Args&&... args
        ) const -> http::request {
            const auto path = fmt::format(
                path_string,
                std::forward<Args>(args)...
            );

            auto req = http::request();

            req.url(host + path);
            req.header("Authorization", auth);

            return req;
        }

        auto send(http::request& req) -> void;
    public:
        elasticsearch() = default;

        elasticsearch(std::string_view host, std::string_view api_key);

        auto about() -> json;

        auto create_doc(
            std::string_view index,
            std::string_view id,
            std::string&& document
        ) -> json;

        auto create_index(std::string_view name) -> void;

        auto delete_doc(
            std::string_view index,
            std::string_view id
        ) -> json;

        auto delete_index(std::string_view name) -> void;

        auto index_exists(std::string_view target) -> bool;

        auto search(
            std::string_view index,
            std::string&& query
        ) -> json;
    };
}
