#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::index_exists(std::string_view target) -> bool {
        auto req = request("/{}", target);

        req.method(http::method::HEAD);

        try {
            send(req);
            return true;
        }
        catch (const es_error& ex) {
            if (ex.status() == 404) return false;
            throw ex;
        }
    }
}
