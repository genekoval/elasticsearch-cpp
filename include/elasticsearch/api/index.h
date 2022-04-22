#pragma once

#include "api.h"

#include <string_view>

namespace elastic {
    struct index_api : api {
        using api::api;

        auto create_index(std::string_view name) const -> void;

        auto delete_index(std::string_view name) const -> void;

        auto exists(std::string_view target) const -> bool;
    };
}
