#pragma once

#include "common.h"

namespace elastic::builder {
    struct delete_index final : void_return<delete_index> {
        delete_index(
            request_bundle&& bundle,
            std::initializer_list<std::string_view> indices
        );

        auto ignore_unavailable(bool ignore) -> delete_index&;
    };
}
