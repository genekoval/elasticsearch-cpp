#pragma once

#include <elasticsearch/elasticsearch.h>

#include <gtest/gtest.h>

namespace elastic::test {
    struct ElasticEnvironment : testing::Environment {
        static auto elasticsearch() -> elasticsearch&;

        virtual auto SetUp() -> void override;
    };
}
