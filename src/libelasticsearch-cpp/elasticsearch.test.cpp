#include "elasticsearch.test.h"

#include <filesystem>
#include <fmt/format.h>
#include <fstream>

constexpr auto env_var = "ES_HOST";
constexpr auto test_file = "test.json";
constexpr auto default_host = "http://127.0.0.1:9200";

auto get_host() -> std::string {
    if (const auto env = std::getenv(env_var)) {
        return env;
    }
    else if (std::filesystem::exists(test_file)) {
        auto file = std::ifstream(test_file);
        auto json = nlohmann::json();
        file >> json;

        return json.at("host").get<std::string>();
    }
    else return default_host;
}
