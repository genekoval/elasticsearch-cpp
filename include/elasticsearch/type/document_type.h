#pragma once

#include "shard_type.h"

#include <string>

namespace elastic {
    struct document_type {
        std::string _index;
        std::string _type;
        std::string _id;
        int _version;
        std::string result;
        shard_type _shards;
        int _seq_no;
        int _primary_term;
    };
}
