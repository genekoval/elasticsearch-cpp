#include "elasticsearch.test.h"

TEST(IndexTest, CreateDelete) {
    constexpr auto index = "test";

    ASSERT_FALSE(es.index_exists(index));

    es.index_create(index);
    ASSERT_TRUE(es.index_exists(index));

    es.index_delete(index);
    ASSERT_FALSE(es.index_exists(index));
}
