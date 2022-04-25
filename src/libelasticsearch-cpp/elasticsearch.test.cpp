#include <internal/test.h>

TEST_F(ElasticTest, About) {
    auto about = client.about();

    const auto version = std::string_view(about["version"]["number"]);

    ASSERT_EQ("8.1.2", version);
}
