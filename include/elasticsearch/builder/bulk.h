#pragma once

#include "../bulk.h"
#include "common.h"

#include <span>

namespace elastic::builder {
    class bulk : public has_return<bulk> {
        const std::string data;
    public:
        bulk(
            request_bundle&& bundle,
            std::optional<std::string_view> index,
            std::span<const elastic::bulk::action> actions
        );
    };
}
