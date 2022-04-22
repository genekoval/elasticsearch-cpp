#include "api/api.h"

namespace elastic {
    auto elasticsearch::search(
        std::string_view index,
        const http::json& query
    ) const -> result_type {
        auto req = request("/{}/_search", index);

        req.header("Content-Type", "application/json");

        req.body(query.dump());

        return get<result_type>(req);
    }
}
