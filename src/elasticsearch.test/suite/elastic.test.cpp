#include <internal/elastic_env.h>
#include <internal/suite.h>

ElasticTest::ElasticTest() :
    client(elastic::test::ElasticEnvironment::elasticsearch()) {}
