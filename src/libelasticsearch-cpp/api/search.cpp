#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::search(
        std::string_view index,
        std::string&& query
    ) -> json {
        auto req = request("/{}/_search", index);

        req.header("Content-Type", "application/json");

        req.body(std::move(query));

        return get(req);
    }
}
