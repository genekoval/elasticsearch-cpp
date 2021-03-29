#include <elasticsearch/except.h>

namespace elastic {
    es_error::es_error(long response_code, const std::string& message) :
        std::runtime_error(message),
        response_code(response_code)
    {}

   auto es_error::status() -> long { return response_code; }
}
