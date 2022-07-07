#include <elasticsearch/builder/index_exists.h>

namespace elastic::builder {
    index_exists::index_exists(
        request_bundle&& bundle,
        std::initializer_list<std::string_view> target
    ) :
        exists(std::move(bundle))
    {
        request().url().path("/{}", fmt::join(target, ","));
    }
}
