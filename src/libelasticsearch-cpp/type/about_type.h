#pragma once

#include "version_type.h"

#include <elasticsearch/type/about_type.h>

#include <nlohmann/json.hpp>

namespace elastic {
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        about_type,
        name,
        cluster_name,
        cluster_uuid,
        version,
        tagline
    )
}
