#pragma once

#include "common.h"

namespace elastic::builder {
    struct search final : has_return<search> {
        search(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view query
        );
    };
}
