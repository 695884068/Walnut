#pragma once

#include "Walnut/Sence/ComponentBase.h"

#include <string>

namespace Walnut
{
    class TagComponent : public ComponentBase
    {
    public:
        std::string Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag)
            : Tag(tag) {}
    };
}