#include <elasticsearch/builder/search.h>

namespace elastic::builder {
    search::search(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view query
    ) :
        has_return(std::forward<request_bundle>(bundle))
    {
        request->method = "GET";
        request->url.path("/{}/_search", index);
        request->data_view(query);
    }
}
