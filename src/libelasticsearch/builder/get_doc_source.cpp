#include <elasticsearch/builder/get_doc_source.h>

namespace elastic::builder {
    get_doc_source::get_doc_source(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id
    ) :
        has_return(std::forward<request_bundle>(bundle))
    {
        request->method(http::method::GET);
        request->url().path("/{}/_source/{}", index, id);
    }
}
