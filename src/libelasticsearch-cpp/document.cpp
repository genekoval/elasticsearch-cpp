#include "json/json.h"

#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    auto elasticsearch::document_create(
        std::string_view index,
        std::string_view id,
        nlohmann::json document
    ) const -> document_type {
        return request(fmt::format("{}/_create/{}", index, id), {
            .body = document.dump(),
            .headers = {
                {"Content-Type", "application/json"}
            },
            .method = http::PUT
        }).json().get<document_type>();
    }

    auto elasticsearch::document_delete(
        std::string_view index,
        std::string_view id
    ) const -> document_type {
        return request(fmt::format("{}/_doc/{}", index, id), {
            .method = http::DELETE
        }).json().get<document_type>();
    }
}
