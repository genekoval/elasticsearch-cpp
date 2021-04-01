#pragma once

#include <http/http>
#include <string_view>

namespace elastic {
    struct version_type {
        std::string number;
        std::string build_flavor;
        std::string build_type;
        std::string build_hash;
        std::string build_date;
        bool build_snapshot;
        std::string lucene_version;
        std::string minimum_wire_compatibility_version;
        std::string minimum_index_compatibility_version;
    };

    struct about_type {
        std::string name;
        std::string cluster_name;
        std::string cluster_uuid;
        version_type version;
        std::string tagline;
    };

    struct shard_type {
        int total;
        int successful;
        int failed;
    };

    struct document_type {
        std::string _index;
        std::string _type;
        std::string _id;
        int _version;
        std::string result;
        shard_type _shards;
        int _seq_no;
        int _primary_term;
    };

    class elasticsearch {
        const http::client* client;
        const std::string host;

        auto request() const -> http::response;

        auto request(std::string_view path) const -> http::response;

        auto request(
            std::string_view path,
            http::options&& options
        ) const -> http::response;
    public:
        elasticsearch(const http::client& client, std::string_view host);

        auto about() const -> about_type;

        auto document_create(
            std::string_view index,
            std::string_view id,
            nlohmann::json document
        ) const -> document_type;

        auto document_delete(
            std::string_view index,
            std::string_view id
        ) const -> document_type;

        auto index_create(std::string_view index) const -> void;

        auto index_delete(std::string_view index) const -> void;

        auto index_exists(std::string_view index) const -> bool;
    };
}
