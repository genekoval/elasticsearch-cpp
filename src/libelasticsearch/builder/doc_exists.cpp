#include <elasticsearch/builder/doc_exists.h>

namespace elastic::builder {
    doc_exists::doc_exists(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id
    ) :
        exists(std::forward<request_bundle>(bundle))
    {
        request->url().path("/{}/_doc/{}", index, id);
    }
}
