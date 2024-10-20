add_subdirectory(libelasticsearch)

if(PROJECT_TESTING)
    add_subdirectory(elasticsearch.test)
endif()
