#include <elasticsearch/builder/get_doc_source.h>

namespace elastic::builder {
    get_doc_source::get_doc_source(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id
    ) :
        has_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::GET);
        req.url().path("/{}/_source/{}", index, id);
    }
}
