#include <elasticsearch/elasticsearch.h>
#include <elasticsearch/except.h>

namespace elastic {
    auto elasticsearch::index_create(std::string_view index) const -> void {
        request(index, {.method = http::PUT});
    }

    auto elasticsearch::index_delete(std::string_view index) const -> void {
        request(index, {.method = http::DELETE});
    }

    auto elasticsearch::index_exists(std::string_view index) const -> bool {
        try {
            return request(index, {.method = http::HEAD}).status() == 200;
        }
        catch (const es_error& ex) {
            if (ex.status() != 404) throw ex;
            return false;
        }
    }
}
