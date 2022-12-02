#include <elasticsearch/builder/delete_doc.h>

namespace elastic::builder {
    delete_doc::delete_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id
    ) :
        has_return(std::forward<request_bundle>(bundle)),
        method(request->method(http::method::GET, "DELETE"))
    {
        request->url().path("/{}/_doc/{}", index, id);
    }
}
