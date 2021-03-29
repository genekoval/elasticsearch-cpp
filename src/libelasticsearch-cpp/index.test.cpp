#include "elasticsearch.test.h"

#include <gtest/gtest.h>

TEST(IndexTest, Create) {
    constexpr auto index = "test";

    es.index_create(index);
}
