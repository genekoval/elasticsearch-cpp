#pragma once

namespace elastic {
    class elasticsearch;

    class api {
    protected:
        const elasticsearch* client;
    public:
        api(const elasticsearch* client);
    };
}
