#include <internal/elastic_env.h>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;

namespace {
    namespace internal {
        struct settings_type {
            std::string node;
            std::string auth;
        };

        NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(settings_type, node, auth)

        const auto settings_path = fs::current_path() / TEST_CONFIG;

        auto read_settings() -> settings_type {
            auto file = std::ifstream(settings_path);
            auto json = nlohmann::json();

            file >> json;

            return json.get<settings_type>();
        }
    }

    auto settings() -> const internal::settings_type& {
        static auto instance = internal::read_settings();
        return instance;
    }
}

namespace elastic::test {
    auto ElasticEnvironment::elasticsearch() -> elastic::elasticsearch& {
        static auto session = http::session();
        static auto instance =
            elastic::elasticsearch(session, settings().node, settings().auth);
        return instance;
    }

    auto ElasticEnvironment::SetUp() -> void { elasticsearch(); }
}
