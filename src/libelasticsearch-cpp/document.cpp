#include "json/json.h"

#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    auto elasticsearch::document_create(
        std::string_view index,
        std::string_view id,
        nlohmann::json document
    ) const -> document_create_type {
        return request(fmt::format("{}/_create/{}", index, id), {
            .body = document.dump(),
            .headers = {
                {"Content-Type", "application/json"}
            },
            .method = http::PUT
        }).json().get<document_create_type>();
    }
}
