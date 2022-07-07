#pragma once

#include "common.h"

namespace elastic::builder {
    class delete_index final : public void_return<delete_index> {
        const http::method_guard method;
    public:
        delete_index(
            request_bundle&& bundle,
            std::initializer_list<std::string_view> indices
        );

        auto ignore_unavailable(bool ignore) -> delete_index&;
    };
}
