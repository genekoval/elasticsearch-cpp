project = elasticsearch-cpp
summary = HTTP-based Elasticsearch client for C++

STD = c++20

library = lib$(project)
$(library).type = shared
define library.libs
 http
endef

test.deps = $(library)
define test.libs
 $(project)
 gtest
 gtest_main
 http
endef

install := $(library)
targets := $(install)

include mkbuild/base.mk
