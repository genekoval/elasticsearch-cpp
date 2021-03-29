#include "json/json.h"

#include <elasticsearch/elasticsearch.h>

namespace elastic {
    elasticsearch::elasticsearch(http::client& client, std::string_view url) :
        client(&client),
        url(url)
    {}

    auto elasticsearch::about() const -> about_type {
        return client->request(url).json().get<about_type>();
    }
}
