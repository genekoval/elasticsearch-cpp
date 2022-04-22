#include "../api.h"

namespace elastic {
    auto index_api::create_index(std::string_view name) const -> void {
        auto req = client->request("/{}", name);

        req.method(http::method::PUT);

        client->get<void>(req);
    }
}
