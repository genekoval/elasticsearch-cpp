#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::create_doc(
        std::string_view index,
        std::string_view id,
        std::string&& document
    ) -> json {
        auto req = request("/{}/_create/{}", index, id);

        req.method(http::method::PUT);

        req.header("Content-Type", "application/json");

        req.body(std::move(document));

        return get(req);
    }
}
