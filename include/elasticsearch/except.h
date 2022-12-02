#pragma once

#include <stdexcept>

namespace elastic {
    struct uninitialized_client : std::exception {
        auto what() const noexcept -> const char* override;
    };

    class es_error : public std::runtime_error {
        const long response_code;
    public:
        es_error(long response_code, std::string_view message);

        auto status() const -> long;
    };
}
