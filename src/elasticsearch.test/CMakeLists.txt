target_sources(elasticsearch.test PRIVATE
    elastic_env.test.cpp
    main.test.cpp
)

add_subdirectory(suite)
