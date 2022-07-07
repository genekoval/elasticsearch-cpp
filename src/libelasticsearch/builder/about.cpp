#include <elasticsearch/builder/about.h>

namespace elastic::builder {
    about::about(request_bundle&& bundle) : has_return(std::move(bundle)) {
        auto& req = request();

        req.method(http::method::GET);
        req.url().path("/");
    }
}
