#include <internal/test.h>

TEST_F(ElasticTest, About) {
    auto about = client.about().send();

    const auto version = about["version"]["number"].get<std::string>();

    ASSERT_EQ("8.1.2", version);
}
