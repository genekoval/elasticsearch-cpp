#include <elasticsearch/builder/about.h>

namespace elastic::builder {
    about::about(request_bundle&& bundle) :
        has_return(std::forward<request_bundle>(bundle)) {
        request->method = "GET";
        request->url.path("/");
    }
}
