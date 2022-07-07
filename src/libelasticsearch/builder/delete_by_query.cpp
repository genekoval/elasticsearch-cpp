#include <elasticsearch/builder/delete_by_query.h>

namespace elastic::builder {
    delete_by_query::delete_by_query(
        request_bundle&& bundle,
        std::initializer_list<std::string_view> target,
        std::string_view query
    ) :
        has_return(std::move(bundle))
    {
        auto& req = request();

        req.method(http::method::POST);
        req.url().path("/{}/_delete_by_query", fmt::join(target, ","));
        req.body(query);
    }
}
