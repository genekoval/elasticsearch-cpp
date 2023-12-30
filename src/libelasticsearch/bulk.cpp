#include <elasticsearch/bulk.h>

#include <nlohmann/json.hpp>
#include <sstream>

using json = nlohmann::json;

namespace {
    auto ndjson(
        std::string_view action,
        const elastic::bulk::options& opts,
        std::optional<std::string_view> source
    ) -> std::string {
        auto options = json::object();

        if (opts.index) options["_index"] = *opts.index;
        if (opts.id) options["_id"] = *opts.id;
        if (opts.require_alias) options["require_alias"] = *opts.require_alias;

        auto out = std::ostringstream();

        out << json({{action, options}}).dump() << "\n";

        if (source) out << *source << "\n";

        return out.str();
    }
}

namespace elastic::bulk {
    _action::_action(std::string&& storage) : storage(std::move(storage)) {}

    _create_action::_create_action(
        std::string_view action,
        const options& opts,
        std::string_view fields
    ) :
        _action(ndjson(action, opts, fields)) {}

    create::create(const options& opts, std::string_view fields) :
        _create_action(name, opts, fields) {}

    del::del(const options& opts) : _action(ndjson(name, opts, {})) {}

    index::index(const options& opts, std::string_view fields) :
        _create_action(name, opts, fields) {}

    update::update(const options& opts, std::string_view doc) :
        _action(ndjson(name, opts, doc)) {}
}
