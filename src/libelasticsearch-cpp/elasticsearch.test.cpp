#include <internal/test.h>

TEST_F(ElasticTest, About) {
    const auto about = client.about();

    ASSERT_EQ("8.1.2", about.version.number);
}
