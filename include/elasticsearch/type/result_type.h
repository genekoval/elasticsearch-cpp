#pragma once

#include <string>
#include <vector>

namespace elastic {
    enum class relation {
        eq,
        gte
    };

    struct total_type {
        int value;
        elastic::relation relation;
    };

    struct hit_type {
        std::string _index;
        std::string _id;
    };

    struct hits_type {
        total_type total;
        std::vector<hit_type> hits;
    };

    struct result_type {
        int took;
        hits_type hits;
    };
}
