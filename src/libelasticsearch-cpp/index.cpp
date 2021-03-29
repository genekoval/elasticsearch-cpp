#include <elasticsearch/elasticsearch.h>

namespace elastic {
    auto elasticsearch::index_create(std::string_view index) const -> void {
        request(index, { .method = http::PUT });
    }
}
