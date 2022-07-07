#pragma once

#include "common.h"

namespace elastic::builder {
    struct update_doc : void_return<update_doc> {
        update_doc(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id,
            std::string_view body
        );
    };
}
