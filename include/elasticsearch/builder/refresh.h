#pragma once

#include "common.h"

namespace elastic::builder {
    struct refresh : void_return<refresh> {
        refresh(
            request_bundle&& bundle,
            std::initializer_list<std::string_view> target
        );
    };
}
