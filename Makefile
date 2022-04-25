project = elasticsearch-cpp
summary = HTTP-based Elasticsearch client for C++

STD = c++20

library = lib$(project)
$(library).type = shared
define library.libs
 http
 fmt
endef

test.deps = $(library)
define test.libs
 $(project)
 gtest
 gtest_main
 http
 fmt
 simdjson
endef

install := $(library)
targets := $(install)

include mkbuild/base.mk

test.config = .test.json

$(obj)/$(test)/elastic_env.test.o: CXXFLAGS += -DTEST_CONFIG='"$(test.config)"'
