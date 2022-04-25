
#pragma once

#include <elasticsearch/elasticsearch>

#include <gtest/gtest.h>

class ElasticTest : public testing::Test {
protected:
    elastic::elasticsearch& client;

    ElasticTest();
};
