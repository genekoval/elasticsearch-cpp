#pragma once

#include <stdexcept>

namespace elastic {
    class es_error : public std::runtime_error {
        const long response_code;
    public:
        es_error(long response_code, const std::string& message);

        auto status() -> long;
    };
}
