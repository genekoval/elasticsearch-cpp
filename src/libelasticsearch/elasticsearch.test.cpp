#include <internal/test.h>

TEST_F(ElasticTest, About) {
    const auto task = [this]() -> ext::task<> {
        const auto about = co_await client.about().send();
        const auto version = about["version"]["number"].get<std::string>();

        EXPECT_EQ("8.1.2", version);
    };

    netcore::async(task());
}
