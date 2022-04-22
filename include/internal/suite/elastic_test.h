
#pragma once

#include <elasticsearch/elasticsearch>

#include <gtest/gtest.h>

class ElasticTest : public testing::Test {
protected:
    const elastic::elasticsearch& client;

    ElasticTest();
};
