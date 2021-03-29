#include "elasticsearch.test.h"

TEST(AboutTest, About) {
    const auto about = es.about();

    ASSERT_EQ("7.12.0", about.version.number);
}
