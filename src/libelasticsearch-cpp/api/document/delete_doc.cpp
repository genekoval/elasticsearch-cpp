#include "../api.h"

namespace elastic {
    auto document_api::delete_doc(
        std::string_view index,
        std::string_view id
    ) -> document_type {
        auto req = client->request("/{}/_doc/{}", index, id);

        req.method("DELETE");

        return client->get<document_type>(req);
    }
}
