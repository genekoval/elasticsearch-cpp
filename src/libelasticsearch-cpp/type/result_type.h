#pragma once

#include <elasticsearch/type/result_type.h>

#include <nlohmann/json.hpp>

namespace elastic {
    auto from_json(const nlohmann::json& json, relation& r) -> void;

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        total_type,
        value,
        relation
    )

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        hit_type,
        _index,
        _id
    )

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        hits_type,
        total,
        hits
    )

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        result_type,
        took,
        hits
    )
}
