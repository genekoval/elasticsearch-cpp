#include <elasticsearch/elasticsearch.h>

#include <fmt/format.h>

namespace elastic {
    elasticsearch::elasticsearch(
        std::string_view host,
        std::string_view api_key
    ) :
        host(host),
        auth(fmt::format("ApiKey {}", api_key))
    {}

    auto elasticsearch::about() -> json {
        auto req = request("/");

        return get(req);
    }

    auto elasticsearch::get(http::request& req) -> json {
        send(req);

        document = parser.iterate(memory.storage);
        return document;
    }

    auto elasticsearch::send(http::request& req) -> void {
        auto res = req.perform(memory);

        if (res.ok()) return;

        throw es_error(res.status(), memory.storage);
    }
}
