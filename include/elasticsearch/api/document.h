#pragma once

#include "api.h"

#include <elasticsearch/type/document_type.h>

#include <http/http>

namespace elastic {
    struct document_api : api {
        using api::api;

        template <typename T>
        auto create_doc(
            std::string_view index,
            std::string_view id,
            T document
        ) const -> document_type {
            const http::json json = document;
            return create_doc(index, id, json);
        }

        auto create_doc(
            std::string_view index,
            std::string_view id,
            const http::json& document
        ) const -> document_type;

        auto delete_doc(
            std::string_view index,
            std::string_view id
        ) -> document_type;
    };
}
