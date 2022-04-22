#include "../api.h"

namespace elastic {
    auto index_api::delete_index(std::string_view name) const -> void {
        auto req = client->request("/{}", name);

        req.method("DELETE");

        client->get<void>(req);
    }
}
