#include <elasticsearch/builder/delete_doc.h>

namespace elastic::builder {
    delete_doc::delete_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id
    ) :
        has_return(std::move(bundle)),
        method(request().method(http::method::GET, "DELETE"))
    {
        auto& req = request();

        req.url().path("/{}/_doc/{}", index, id);
    }
}
