#pragma once

#include "../bulk.h"
#include "common.h"

#include <span>

namespace elastic::builder {
    struct bulk : has_return<bulk> {
        bulk(
            request_bundle&& bundle,
            std::optional<std::string_view> index,
            std::span<const elastic::bulk::action> actions
        );
    };
}
