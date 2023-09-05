#include <elasticsearch/builder/bulk.h>

namespace {
    namespace internal {
        auto bulk(
            std::span<const elastic::bulk::action> actions
        ) -> std::string {
            auto out = std::ostringstream();

            for (const auto& action : actions) {
                out << std::visit([](auto&& arg) -> std::string_view {
                    return arg.storage;
                }, action);
            }

            return out.str();
        }
    }
}

namespace elastic::builder {
    bulk::bulk(
        request_bundle&& bundle,
        std::optional<std::string_view> index,
        std::span<const elastic::bulk::action> actions
    ) :
        has_return(std::forward<request_bundle>(bundle)),
        data(internal::bulk(actions))
    {
        request->method = "POST";

        if (index) request->url.path("/{}/_bulk", *index);
        else request->url.path("/_bulk");

        request->data(data);
    }
}
