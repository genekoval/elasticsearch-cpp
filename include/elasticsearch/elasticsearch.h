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
        http::client* client;
        std::string url;
    public:
        elasticsearch(http::client& client, std::string_view url);

        auto about() const -> about_type;
    };
}
