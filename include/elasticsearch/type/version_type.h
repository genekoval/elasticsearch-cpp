#pragma once

#include <string>

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
}
