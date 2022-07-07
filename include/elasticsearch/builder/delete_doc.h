#pragma once

#include "common.h"

namespace elastic::builder {
    class delete_doc : public has_return<delete_doc> {
        const http::method_guard method;
    public:
        delete_doc(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id
        );
    };
}
