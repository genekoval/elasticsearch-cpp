#pragma once

#include "common.h"

namespace elastic::builder {
    struct about : has_return<about> {
        about(request_bundle&& bundle);
    };
}
