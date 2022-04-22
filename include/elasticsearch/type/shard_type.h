#pragma once

namespace elastic {
    struct shard_type {
        int total;
        int successful;
        int failed;
    };
}
