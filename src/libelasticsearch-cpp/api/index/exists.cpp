#include "../api.h"

namespace elastic {
    auto index_api::exists(std::string_view target) const -> bool {
        auto req = client->request("/{}", target);

        req.method(http::method::HEAD);

        try {
            client->get<void>(req);
            return true;
        }
        catch (const es_error& ex) {
            if (ex.status() == 404) return false;
            throw ex;
        }
    }
}
