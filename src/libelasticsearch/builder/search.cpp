#include <elasticsearch/builder/search.h>

namespace elastic::builder {
    search::search(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view query
    ) :
        has_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::GET);
        req.url().path("/{}/_search", index);
        req.body(query);
    }
}
