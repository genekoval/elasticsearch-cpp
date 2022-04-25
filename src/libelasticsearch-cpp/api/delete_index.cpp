#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::delete_index(std::string_view name) -> void {
        auto req = request("/{}", name);

        req.method("DELETE");

        send(req);
    }
}
