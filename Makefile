project = elasticsearch
summary = HTTP-based Elasticsearch client for C++

STD = c++20

library = lib$(project)
$(library).type = shared
$(library).libs = http fmt timber

test.deps = $(library)
test.libs = \
 $(project) \
 ext++ \
 gtest \
 http \
 fmt \
 simdjson \
 timber

install := $(library)
targets := $(install)

install.directories = $(include)/$(project)

files = $(include) $(src) Makefile VERSION

include mkbuild/base.mk

defines.release = NDEBUG

test.config = .test.json

$(obj)/$(test)/elastic_env.test.o: CXXFLAGS += -DTEST_CONFIG='"$(test.config)"'
