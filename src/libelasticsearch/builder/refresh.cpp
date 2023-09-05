#include <elasticsearch/builder/refresh.h>

namespace elastic::builder {
    refresh::refresh(
        request_bundle&& bundle,
        std::initializer_list<std::string_view> target
    ) :
        void_return(std::forward<request_bundle>(bundle))
    {
        request->method = "POST";
        request->url.path("/{}/_refresh", fmt::join(target, ","));
    }
}
