#pragma once

#include "common.h"

namespace elastic::builder {
    struct index_exists final : exists<index_exists> {
        index_exists(
            request_bundle&& bundle,
            std::initializer_list<std::string_view> target
        );
    };
}
