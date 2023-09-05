#include <elasticsearch/builder/create_index.h>

namespace elastic::builder {
    create_index::create_index(
        request_bundle&& bundle,
        std::string_view name,
        std::string_view config
    ) :
        void_return(std::forward<request_bundle>(bundle))
    {
        request->method = "PUT";
        request->url.path("/{}", name);
        if (!config.empty()) request->data(config);
    }
}
