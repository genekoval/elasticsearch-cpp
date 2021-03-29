#include "json/json.h"

#include <elasticsearch/elasticsearch.h>
#include <elasticsearch/except.h>

#include <fmt/format.h>

namespace elastic {
    elasticsearch::elasticsearch(
        const http::client& client,
        std::string_view host
    ) :
        client(&client),
        host(host.ends_with('/') ? host.substr(0, host.size() - 1) : host)
    {}

    auto elasticsearch::about() const -> about_type {
        return request().json().get<about_type>();
    }

    auto elasticsearch::request() const -> http::response {
        return request("", {});
    }

    auto elasticsearch::request(std::string_view path) const -> http::response {
        return request(path, {});
    }

    auto elasticsearch::request(
        std::string_view path,
        http::options options
    ) const -> http::response {
        const auto url = fmt::format("{}/{}", host, path);
        auto res = client->request(url);

        if (!res.ok()) {
            throw es_error(res.status(), res.text());
        }

        return res;
    }
}
