#include <elasticsearch/builder/refresh.h>

namespace elastic::builder {
    refresh::refresh(
        request_bundle&& bundle,
        std::initializer_list<std::string_view> target
    ) :
        void_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::POST);
        req.url().path("/{}/_refresh", fmt::join(target, ","));
    }
}
