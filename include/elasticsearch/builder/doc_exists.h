#pragma once

#include "common.h"

namespace elastic::builder {
    struct doc_exists final : exists<doc_exists> {
        doc_exists(
            request_bundle&& bundle,
            std::string_view index,
            std::string_view id
        );
    };
}
