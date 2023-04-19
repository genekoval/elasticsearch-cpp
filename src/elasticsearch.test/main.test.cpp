#include <internal/elastic_env.h>

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);

    const auto runtime = netcore::runtime();

    testing::AddGlobalTestEnvironment(new elastic::test::ElasticEnvironment);

    return RUN_ALL_TESTS();
}
