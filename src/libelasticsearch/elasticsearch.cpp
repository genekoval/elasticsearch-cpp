#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    elasticsearch::request_provider::request_provider(
        std::string_view host,
        std::string_view auth
    ) :
        host(host),
        auth(auth)
    {}

    auto elasticsearch::bulk_provider::provide() -> http::request {
        auto request = http::request();

        request.method(http::method::POST);
        request.url().set(CURLUPART_URL, host.data());
        request.headers({
            {"Authorization", auth},
            {"Content-Type", "application/x-ndjson"}
        });

        return request;
    }

    auto elasticsearch::json_provider::provide() -> http::request {
        auto request = http::request();

        request.url().set(CURLUPART_URL, host.data());
        request.headers({
            {"Authorization", auth},
            {"Content-Type", "application/json"}
        });
        return request;
    }

    auto elasticsearch::url_provider::provide() -> http::request {
        auto request = http::request();

        request.url().set(CURLUPART_URL, host.data());
        request.headers({
            {"Authorization", auth}
        });

        return request;
    }

    elasticsearch::elasticsearch(
        std::string_view host,
        std::string_view api_key
    ) :
        host(host),
        auth(fmt::format("ApiKey {}", api_key)),
        client(std::in_place),
        bulk_requests(bulk_provider(this->host, this->auth)),
        json_requests(json_provider(this->host, this->auth)),
        url_requests(url_provider(this->host, this->auth))
    {}

    auto elasticsearch::about() -> builder::about {
        return {bundle(url_requests)};
    }

    auto elasticsearch::bulk(
        std::span<const bulk::action> actions
    ) -> builder::bulk {
        return {bundle(bulk_requests), {}, actions};
    }

    auto elasticsearch::bulk(
        std::string_view index,
        std::span<const bulk::action> actions
    ) -> builder::bulk {
        return {bundle(bulk_requests), index, actions};
    }

    auto elasticsearch::create_doc(
        std::string_view index,
        std::string_view id,
        std::string_view document
    ) -> builder::create_doc {
        return {bundle(json_requests), index, id, document};
    }

    auto elasticsearch::create_index(
        std::string_view name,
        std::string_view config
    ) -> builder::create_index {
        auto bundle = std::optional<builder::request_bundle>();

        if (config.empty()) bundle.emplace(this->bundle(url_requests));
        else bundle.emplace(this->bundle(json_requests));

        return {
            *std::move(bundle),
            name,
            config
        };
    }

    auto elasticsearch::delete_by_query(
        std::initializer_list<std::string_view> target,
        std::string_view query
    ) -> builder::delete_by_query {
        return {bundle(json_requests), target, query};
    }

    auto elasticsearch::delete_doc(
        std::string_view index,
        std::string_view id
    ) -> builder::delete_doc {
        return {bundle(url_requests), index, id};
    }

    auto elasticsearch::delete_index(
        std::initializer_list<std::string_view> indices
    ) -> builder::delete_index {
        return {bundle(url_requests), indices};
    }

    auto elasticsearch::doc_exists(
        std::string_view index,
        std::string_view id
    ) -> builder::doc_exists {
        return {bundle(url_requests), index, id};
    }

    auto elasticsearch::get_doc_source(
        std::string_view index,
        std::string_view id
    ) -> builder::get_doc_source {
        return {bundle(url_requests), index, id};
    }

    auto elasticsearch::index_exists(
        std::initializer_list<std::string_view> target
    ) -> builder::index_exists {
        return {bundle(url_requests), target};
    }

    auto elasticsearch::refresh(
        std::initializer_list<std::string_view> target
    ) -> builder::refresh {
        return {bundle(url_requests), target};
    }

    auto elasticsearch::search(
        std::string_view index,
        std::string_view query
    ) -> builder::search {
        return {bundle(json_requests), index, query};
    }

    auto elasticsearch::update_doc(
        std::string_view index,
        std::string_view id,
        std::string_view body
    ) -> builder::update_doc {
        return {bundle(json_requests), index, id, body};
    }
}
