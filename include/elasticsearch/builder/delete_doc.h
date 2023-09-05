#pragma once

#include "common.h"

namespace elastic::builder {
    struct delete_doc : has_return<delete_doc> {
        delete_doc(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id
        );
    };
}
