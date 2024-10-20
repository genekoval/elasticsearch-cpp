cmake_minimum_required(VERSION 3.27)

include(cmake/modules.cmake)
include(GitVersion)

project(elasticsearch
    VERSION ${GIT_VERSION_ABBREV}
    DESCRIPTION "Unofficial HTTP-based Elasticsearch client for C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

include(ProjectTesting)
include(packages.cmake)

add_library(elasticsearch)
add_library(${PROJECT_NAME}::elasticsearch ALIAS elasticsearch)
target_sources(elasticsearch PUBLIC FILE_SET HEADERS BASE_DIRS include)
target_link_libraries(elasticsearch
    PUBLIC
        http::http
        nlohmann_json::nlohmann_json
        timber::timber
    PRIVATE
        fmt::fmt
)

if(PROJECT_TESTING)
    add_executable(elasticsearch.test)
    target_link_libraries(elasticsearch.test PRIVATE
        elasticsearch::elasticsearch
        GTest::gtest
    )
    target_compile_definitions(elasticsearch.test PRIVATE
        TEST_CONFIG=\".test.json\"
    )
    add_test(
        NAME "Unit Tests"
        COMMAND elasticsearch.test
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
endif()

add_subdirectory(include)
add_subdirectory(src)

include(Sanitizers)
enable_asan()

include(EasyInstall)
easy_install(
    TARGETS elasticsearch
    DEPENDENCIES
        http
        nlohmann_json
        timber
)

if(PROJECT_IS_TOP_LEVEL)
    add_custom_target(docker
        docker build --progress=plain --no-cache .
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        USES_TERMINAL
    )
endif()
