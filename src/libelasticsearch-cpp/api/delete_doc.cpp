#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::delete_doc(
        std::string_view index,
        std::string_view id
    ) -> json {
        auto req = request("/{}/_doc/{}", index, id);

        req.method("DELETE");

        return get(req);
    }
}
