#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::create_index(std::string_view name) -> void {
        auto req = request("/{}", name);

        req.method(http::method::PUT);

        send(req);
    }
}
