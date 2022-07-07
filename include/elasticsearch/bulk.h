#pragma once

#include <optional>
#include <string>
#include <variant>

namespace elastic::bulk {
    struct options final {
        const std::optional<std::string> index;
        const std::optional<std::string> id;
        const std::optional<bool> require_alias;
    };

    struct _action {
        const std::string storage;

        _action(std::string&& storage);
    };

    struct _create_action : _action {
        _create_action(
            std::string_view action,
            const options& opts,
            std::string_view fields
        );
    };

    struct create final : _create_action {
        static constexpr auto name = "create";

        create(const options& opts, std::string_view fields);
    };

    struct del final : _action {
        static constexpr auto name = "delete";

        del(const options& opts);
    };

    struct index final : _create_action {
        static constexpr auto name = "index";

        index(const options& opts, std::string_view fields);
    };

    struct update final : _action {
        static constexpr auto name = "update";

        update(const options& opts, std::string_view doc);
    };

    using action = std::variant<create, del, index, update>;
}
