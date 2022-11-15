#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    elasticsearch::elasticsearch(
        std::string_view host,
        std::string_view api_key
    ) :
        host(host),
        auth(fmt::format("ApiKey {}", api_key))
    {
        bulk_request.method(http::method::POST);
        bulk_request.url().set(CURLUPART_URL, this->host);
        bulk_request.headers({
            {"Authorization", auth},
            {"Content-Type", "application/x-ndjson"}
        });

        url_request.url().set(CURLUPART_URL, this->host);
        url_request.headers({
            {"Authorization", auth}
        });

        json_request.url().set(CURLUPART_URL, this->host);
        json_request.headers({
            {"Authorization", auth},
            {"Content-Type", "application/json"}
        });
    }

    auto elasticsearch::about() -> builder::about {
        return {bundle(url_request)};
    }

    auto elasticsearch::bulk(
        std::span<const bulk::action> actions
    ) -> builder::bulk {
        return {bundle(bulk_request), {}, actions};
    }

    auto elasticsearch::bulk(
        std::string_view index,
        std::span<const bulk::action> actions
    ) -> builder::bulk {
        return {bundle(bulk_request), index, actions};
    }

    auto elasticsearch::bundle(
        http::request& request
    ) -> builder::request_bundle {
        return {
            .request = &request,
            .memory = &memory,
        };
    }

    auto elasticsearch::create_doc(
        std::string_view index,
        std::string_view id,
        std::string_view document
    ) -> builder::create_doc {
        return {bundle(json_request), index, id, document};
    }

    auto elasticsearch::create_index(
        std::string_view name,
        std::string_view config
    ) -> builder::create_index {
        return {
            bundle(config.empty() ? url_request : json_request),
            name,
            config
        };
    }

    auto elasticsearch::delete_by_query(
        std::initializer_list<std::string_view> target,
        std::string_view query
    ) -> builder::delete_by_query {
        return {bundle(json_request), target, query};
    }

    auto elasticsearch::delete_doc(
        std::string_view index,
        std::string_view id
    ) -> builder::delete_doc {
        return {bundle(url_request), index, id};
    }

    auto elasticsearch::delete_index(
        std::initializer_list<std::string_view> indices
    ) -> builder::delete_index {
        return {bundle(url_request), indices};
    }

    auto elasticsearch::doc_exists(
        std::string_view index,
        std::string_view id
    ) -> builder::doc_exists {
        return {bundle(url_request), index, id};
    }

    auto elasticsearch::get_doc_source(
        std::string_view index,
        std::string_view id
    ) -> builder::get_doc_source {
        return {bundle(url_request), index, id};
    }

    auto elasticsearch::index_exists(
        std::initializer_list<std::string_view> target
    ) -> builder::index_exists {
        return {bundle(url_request), target};
    }

    auto elasticsearch::refresh(
        std::initializer_list<std::string_view> target
    ) -> builder::refresh {
        return {bundle(url_request), target};
    }

    auto elasticsearch::search(
        std::string_view index,
        std::string_view query
    ) -> builder::search {
        return {bundle(json_request), index, query};
    }

    auto elasticsearch::update_doc(
        std::string_view index,
        std::string_view id,
        std::string_view body
    ) -> builder::update_doc {
        return {bundle(json_request), index, id, body};
    }
}
