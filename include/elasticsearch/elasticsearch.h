#pragma once

#include "api/document.h"
#include "api/index.h"
#include "except.h"
#include "type/about_type.h"

#include <http/http>
#include <string_view>

namespace elastic {
    class elasticsearch {
        friend class document_api;
        friend class index_api;

        const std::string host;
        const std::string auth;

        template <typename R>
        auto get(http::request& req) const -> R {
            auto res = req.perform();

            if (res.ok()) {
                if constexpr (std::is_same_v<R, void>) return;
                else {
                    return res.json().template get<R>();
                }
            }

            throw es_error(res.status(), res.text());
        }

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
            req.header("Authorization", fmt::format("ApiKey {}", auth));

            return req;
        }
    public:
        const document_api documents;
        const index_api indices;

        elasticsearch(std::string_view host, std::string_view api_key);

        elasticsearch(const elasticsearch&) = delete;

        elasticsearch& operator=(const elasticsearch&) = delete;

        auto about() const -> about_type;
    };
}
