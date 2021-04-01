#include "elasticsearch.test.h"

TEST(DocumentTest, CreateDelete) {
    constexpr auto index = "test";
    constexpr auto id = "1";

    const auto document = R"({
        "name": "document"
    })"_json;

    auto res = es.document_create(index, id, document);

    ASSERT_EQ(index, res._index);
    ASSERT_EQ(id, res._id);
    ASSERT_EQ("created", res.result);

    res = es.document_delete(index, id);

    ASSERT_EQ(index, res._index);
    ASSERT_EQ(id, res._id);
    ASSERT_EQ("deleted", res.result);
}
