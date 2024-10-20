if(PROJECT_TESTING)
    target_sources(elasticsearch.test PRIVATE
        index.test.cpp
    )
endif()
