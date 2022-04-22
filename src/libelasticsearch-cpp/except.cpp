#include <elasticsearch/except.h>

#include <nlohmann/json.hpp>

namespace {
    struct error_type {
        std::string reason;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        error_type,
        reason
    )

    auto parse_error(const std::string& string) -> std::string {
        if (string.empty()) return string;

        const auto json = nlohmann::json::parse(string);
        const auto& error = json["error"];

        if (error.is_string()) return error.get<std::string>();

        return error.get<error_type>().reason;
    }
}

namespace elastic {
    es_error::es_error(long response_code, const std::string& message) :
        std::runtime_error(parse_error(message)),
        response_code(response_code)
    {}

   auto es_error::status() const -> long { return response_code; }
}
