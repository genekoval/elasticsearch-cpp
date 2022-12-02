#include <internal/suite.h>

TEST_F(IndexTest, Index) {
    constexpr auto index = "elastic-test-index";

    const auto task = [this]() -> ext::task<> {
        co_await client.create_index(index).send();
        EXPECT_TRUE(co_await client.index_exists({index}).send());

        co_await client.delete_index({index}).send();
        EXPECT_FALSE(co_await client.index_exists({index}).send());
    };

    netcore::async(task());
}
