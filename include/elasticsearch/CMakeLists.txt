target_sources(elasticsearch PUBLIC FILE_SET HEADERS FILES
    bulk.h
    elasticsearch
    elasticsearch.h
    except.h
)

add_subdirectory(builder)
