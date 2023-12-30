#include <elasticsearch/except.h>

namespace elastic {
    auto uninitialized_client::what() const noexcept -> const char* {
        return "Elasticsearch client not initialized";
    }

    es_error::es_error(long response_code, std::string_view message) :
        std::runtime_error(std::string(message)),
        response_code(response_code) {}

    auto es_error::status() const -> long { return response_code; }
}
