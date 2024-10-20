include(FetchContent)

cmake_policy(PUSH)
cmake_policy(SET CMP0150 NEW)

FetchContent_Declare(http
    GIT_REPOSITORY ../libhttp.git
    GIT_TAG        d4f761d67d01363dcd28d3bb5b099f0aa79db731 # 0.3.0
)

set(FMT_INSTALL ON)
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        a33701196adfad74917046096bf5a2aa0ab0bb50 # 9.1.0
)

FetchContent_Declare(GTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        b10fad38c4026a29ea6561ab15fc4818170d1c10 # branch: main
)

set(JSON_Install ON)
FetchContent_Declare(nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d # v3.11.2
)

FetchContent_Declare(timber
    GIT_REPOSITORY ../timber.git
    GIT_TAG        9e6fd332fc3dc80a14ad8d5476a268ea867714f0 # 0.4.0
)

FetchContent_MakeAvailable(http fmt nlohmann_json timber)

if(PROJECT_TESTING)
    FetchContent_MakeAvailable(GTest)
endif()

cmake_policy(POP)
