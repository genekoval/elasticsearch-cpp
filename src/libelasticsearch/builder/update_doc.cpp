#include <elasticsearch/builder/update_doc.h>

namespace elastic::builder {
    update_doc::update_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id,
        std::string_view body
    ) :
        void_return(std::forward<request_bundle>(bundle)) {
        request->method = "POST";
        request->url.path("/{}/_update/{}", index, id);
        request->data_view(body);
    }
}
