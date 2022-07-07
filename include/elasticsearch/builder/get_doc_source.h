#pragma once

#include "common.h"

namespace elastic::builder {
    struct get_doc_source : has_return<get_doc_source> {
        get_doc_source(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id
        );
    };
}
