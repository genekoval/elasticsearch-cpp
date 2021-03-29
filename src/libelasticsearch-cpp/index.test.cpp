#include "elasticsearch.test.h"

TEST(IndexTest, Create) {
    constexpr auto index = "test";

    es.index_create(index);
}
