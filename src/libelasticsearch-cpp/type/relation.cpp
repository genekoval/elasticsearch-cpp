#include "result_type.h"

namespace elastic {
    auto from_json(const nlohmann::json& json, relation& r) -> void {
        const auto value = json.get<std::string>();

        if (value == "eq") r = relation::eq;
        else if (value == "gte") r = relation::gte;
        else throw std::runtime_error("failed to parse relation: " + value);
    }
}
