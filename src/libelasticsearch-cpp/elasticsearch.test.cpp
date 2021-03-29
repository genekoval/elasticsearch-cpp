#include "elasticsearch.test.h"

#include <fmt/format.h>

static constexpr auto env_var = "ES_HOST";

auto get_host() -> std::string {
    if (const auto env = std::getenv(env_var)) {
        return env;
    }
    else {
        throw std::runtime_error(fmt::format(
            "environment variable '{}' is undefined",
            env_var
        ));
    }
}
