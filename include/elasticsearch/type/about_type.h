#pragma once

#include "version_type.h"

namespace elastic {
    struct about_type {
        std::string name;
        std::string cluster_name;
        std::string cluster_uuid;
        version_type version;
        std::string tagline;
    };
}
