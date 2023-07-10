#include <internal/elastic_env.h>

#include <http/http>

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);

    const auto init = http::init();
    const auto runtime = netcore::runtime();

    testing::AddGlobalTestEnvironment(new elastic::test::ElasticEnvironment);

    return RUN_ALL_TESTS();
}
