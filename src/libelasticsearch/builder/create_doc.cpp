#include <elasticsearch/builder/create_doc.h>

namespace elastic::builder {
    create_doc::create_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id,
        std::string_view document
    ) :
        has_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::PUT);
        req.url().path("/{}/_create/{}", index, id);
        req.body(document);
    }
}
