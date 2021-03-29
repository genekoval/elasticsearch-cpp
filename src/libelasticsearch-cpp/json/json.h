#pragma once

#include <elasticsearch/elasticsearch.h>

#include <nlohmann/json.hpp>

namespace elastic {
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        version_type,
        number,
        build_flavor,
        build_type,
        build_hash,
        build_date,
        build_snapshot,
        lucene_version,
        minimum_wire_compatibility_version,
        minimum_index_compatibility_version
    )

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        about_type,
        name,
        cluster_name,
        cluster_uuid,
        version,
        tagline
    )
}