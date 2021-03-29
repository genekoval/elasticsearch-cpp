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

    class elasticsearch {
        const http::client* client;
        const std::string host;

        auto request() const -> http::response;

        auto request(std::string_view path) const -> http::response;

        auto request(
            std::string_view path,
            http::options options
        ) const -> http::response;
    public:
        elasticsearch(const http::client& client, std::string_view host);

        auto about() const -> about_type;

        auto index_create(std::string_view index) const -> void;
    };
}
