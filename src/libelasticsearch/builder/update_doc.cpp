#include <elasticsearch/builder/update_doc.h>

namespace elastic::builder {
    update_doc::update_doc(
        request_bundle&& bundle,
        std::string_view index,
        std::string_view id,
        std::string_view body
    ) :
        void_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::POST);
        req.url().path("/{}/_update/{}", index, id);
        req.body(body);
    }
}
