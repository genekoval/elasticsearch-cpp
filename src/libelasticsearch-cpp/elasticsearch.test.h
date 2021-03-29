#pragma once

#include <elasticsearch/elasticsearch>
#include <gtest/gtest.h>

auto get_host() -> std::string;

const auto client = http::client();
const auto es = elastic::elasticsearch(client, get_host());
