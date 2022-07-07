#pragma once

#include "common.h"

namespace elastic::builder {
    struct create_index : void_return<create_index> {
        create_index(
            request_bundle&& bundle,
            std::string_view name,
            std::string_view config
        );
    };
}
