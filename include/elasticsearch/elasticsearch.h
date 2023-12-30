#pragma once

#include "builder/builder.h"

#include <span>

namespace elastic {
    class elasticsearch {
        class request_provider {
        protected:
            const std::string_view host;
            const std::string_view auth;
        public:
            request_provider() = default;

            request_provider(std::string_view host, std::string_view auth);
        };

        struct bulk_provider : request_provider {
            using request_provider::request_provider;

            auto provide() -> http::request;
        };

        struct url_provider : request_provider {
            using request_provider::request_provider;

            auto provide() -> http::request;
        };

        struct json_provider : request_provider {
            using request_provider::request_provider;

            auto provide() -> http::request;
        };

        const std::string host;
        const std::string auth;

        http::session* session;

        ext::pool<bulk_provider> bulk_requests;
        ext::pool<json_provider> json_requests;
        ext::pool<url_provider> url_requests;

        template <typename Provider>
        auto bundle(ext::pool<Provider>& pool) -> builder::request_bundle {
            if (!session) throw uninitialized_client();

            return {.request = pool.checkout(), .session = *session};
        }
    public:
        elasticsearch() = default;

        elasticsearch(
            http::session& session,
            std::string_view host,
            std::string_view api_key
        );

        auto about() -> builder::about;

        auto bulk(std::span<const bulk::action> actions) -> builder::bulk;

        auto bulk(std::string_view index, std::span<const bulk::action> actions)
            -> builder::bulk;

        auto create_doc(
            std::string_view index,
            std::string_view id,
            std::string_view document
        ) -> builder::create_doc;

        auto create_index(
            std::string_view name,
            std::string_view config = std::string_view()
        ) -> builder::create_index;

        auto delete_by_query(
            std::initializer_list<std::string_view> target,
            std::string_view query
        ) -> builder::delete_by_query;

        auto delete_doc(std::string_view index, std::string_view id)
            -> builder::delete_doc;

        auto delete_index(std::initializer_list<std::string_view> indices)
            -> builder::delete_index;

        auto doc_exists(std::string_view index, std::string_view id)
            -> builder::doc_exists;

        auto get_doc_source(std::string_view index, std::string_view id)
            -> builder::get_doc_source;

        auto index_exists(std::initializer_list<std::string_view> target)
            -> builder::index_exists;

        auto refresh(std::initializer_list<std::string_view> target)
            -> builder::refresh;

        auto search(std::string_view index, std::string_view query)
            -> builder::search;

        auto update_doc(
            std::string_view index,
            std::string_view id,
            std::string_view body
        ) -> builder::update_doc;
    };
}
