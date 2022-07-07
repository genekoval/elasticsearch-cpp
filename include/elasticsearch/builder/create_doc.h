#pragma once

#include "common.h"

namespace elastic::builder {
    struct create_doc : has_return<create_doc> {
        create_doc(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id,
            std::string_view document
        );
    };
}
