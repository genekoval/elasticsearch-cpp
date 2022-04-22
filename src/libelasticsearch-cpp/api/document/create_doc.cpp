#include "../api.h"

namespace elastic {
    template <>
    auto document_api::create_doc(
        std::string_view index,
        std::string_view id,
        const http::json& document
    ) const -> document_type {
        auto req = client->request("/{}/_create/{}", index, id);

        req.method(http::method::PUT);

        req.header("Content-Type", "application/json");

        req.body(document.dump());

        return client->get<document_type>(req);
    }
}
