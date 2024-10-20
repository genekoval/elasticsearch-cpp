target_sources(elasticsearch PRIVATE
    bulk.cpp
    elasticsearch.cpp
    except.cpp
)

if(PROJECT_TESTING)
    target_sources(elasticsearch.test PRIVATE
        elasticsearch.test.cpp
    )
endif()

add_subdirectory(api)
add_subdirectory(builder)
