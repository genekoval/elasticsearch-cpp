#include <elasticsearch/builder/delete_index.h>

namespace elastic::builder {
    delete_index::delete_index(
        request_bundle&& bundle,
        std::initializer_list<std::string_view> indices
    ) :
        void_return(std::forward<request_bundle>(bundle)),
        method(request->method(http::method::GET, "DELETE"))
    {
        request->url().path("/{}", fmt::join(indices, ","));
    }

    auto delete_index::ignore_unavailable(bool ignore) -> delete_index& {
        request->url().append_query(__FUNCTION__, ignore);
        return *this;
    }
}
