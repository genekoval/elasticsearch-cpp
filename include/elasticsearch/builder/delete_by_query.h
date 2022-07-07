#pragma once

#include "common.h"

namespace elastic::builder {
    struct delete_by_query : has_return<delete_by_query> {
        delete_by_query(
            request_bundle&& bundle,
            std::initializer_list<std::string_view> target,
            std::string_view query
        );
    };
}
