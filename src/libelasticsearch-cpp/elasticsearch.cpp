#include "type/type.h"

#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    elasticsearch::elasticsearch(
        std::string_view host,
        std::string_view api_key
    ) :
        host(host),
        auth(api_key),
        documents(this),
        indices(this)
    {}

    auto elasticsearch::about() const -> about_type {
        auto req = request("/");

        return get<about_type>(req);
    }
}
