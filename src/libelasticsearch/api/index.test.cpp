#include <internal/suite.h>

TEST_F(IndexTest, Index) {
    constexpr auto index = "elastic-test-index";

    client.create_index(index);
    ASSERT_TRUE(client.index_exists({index}).send());

    client.delete_index({index}).send();
    ASSERT_FALSE(client.index_exists({index}).send());
}
