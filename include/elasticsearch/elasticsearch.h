#pragma once

#include "builder/builder.h"
#include "except.h"

#include <http/http>
#include <simdjson.h>
#include <span>

namespace elastic {
    class elasticsearch {
        const std::string host;
        const std::string auth;

        http::request bulk_request;
        http::request url_request;
        http::request json_request;

        http::memory memory = { .padding = simdjson::SIMDJSON_PADDING };
        simdjson::ondemand::parser parser;
        simdjson::ondemand::document document;

        auto bundle(http::request& request) -> builder::request_bundle;
    public:
        elasticsearch() = default;

        elasticsearch(std::string_view host, std::string_view api_key);

        auto about() -> builder::about;

        auto bulk(std::span<const bulk::action> actions) -> builder::bulk;

        auto bulk(
            std::string_view index,
            std::span<const bulk::action> actions
        ) -> builder::bulk;

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

        auto delete_doc(
            std::string_view index,
            std::string_view id
        ) -> builder::delete_doc;

        auto delete_index(
            std::initializer_list<std::string_view> indices
        ) -> builder::delete_index;

        auto doc_exists(
            std::string_view index,
            std::string_view id
        ) -> builder::doc_exists;

        auto get_doc_source(
            std::string_view index,
            std::string_view id
        ) -> builder::get_doc_source;

        auto index_exists(
            std::initializer_list<std::string_view> target
        ) -> builder::index_exists;

        auto refresh(
            std::initializer_list<std::string_view> target
        ) -> builder::refresh;

        auto search(
            std::string_view index,
            std::string_view query
        ) -> builder::search;

        auto update_doc(
            std::string_view index,
            std::string_view id,
            std::string_view body
        ) -> builder::update_doc;
    };
}
