#pragma once

#include <entt.hpp>

namespace Walnut
{
    // TODO
    // A wrapper of entt::registry

    class Registry final
    {
    public:
        Registry() = default;
        ~Registry() = default;
    public:

    private:
        entt::registry mRegistry;
    };
}