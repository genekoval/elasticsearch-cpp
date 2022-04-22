#include <internal/suite.h>

TEST_F(IndexTest, Index) {
    constexpr auto index = "elastic-test-index";

    client.indices.create_index(index);
    ASSERT_TRUE(client.indices.exists(index));

    client.indices.delete_index(index);
    ASSERT_FALSE(client.indices.exists(index));
}
