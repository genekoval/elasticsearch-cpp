#include <elasticsearch/builder/create_doc.h>

namespace elastic::builder {
    create_doc::create_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id,
        std::string_view document
    ) :
        has_return(std::forward<request_bundle>(bundle)) {
        request->method = "PUT";
        request->url.path("/{}/_create/{}", index, id);
        request->data_view(document);
    }
}
