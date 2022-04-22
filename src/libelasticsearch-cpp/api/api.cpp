#include <elasticsearch/api/api.h>

namespace elastic {
    api::api(const elasticsearch* client) : client(client) {}
}
