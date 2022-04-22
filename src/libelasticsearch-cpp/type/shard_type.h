#pragma once

#include <elasticsearch/type/shard_type.h>

#include <nlohmann/json.hpp>

namespace elastic {
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        shard_type,
        total,
        successful,
        failed
    )
}
