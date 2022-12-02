#pragma once

#include <elasticsearch/elasticsearch>

#include <gtest/gtest.h>
#include <netcore/netcore>

class ElasticTest : public testing::Test {
protected:
    elastic::elasticsearch& client;

    ElasticTest();
};
