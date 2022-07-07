#include <elasticsearch/builder/create_index.h>

namespace elastic::builder {
    create_index::create_index(
        request_bundle&& bundle,
        std::string_view name,
        std::string_view config
    ) :
        void_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::PUT);
        req.url().path("/{}", name);
        if (!config.empty()) req.body(config);
    }
}
