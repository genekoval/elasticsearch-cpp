#pragma once

#include "shard_type.h"

#include <elasticsearch/type/document_type.h>

#include <nlohmann/json.hpp>

namespace elastic {
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        document_type,
        _index,
        _type,
        _id,
        _version,
        result,
        _shards,
        _seq_no,
        _primary_term
    )
}
