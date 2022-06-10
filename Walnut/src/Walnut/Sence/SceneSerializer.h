#pragma once

#include "Walnut/Core/Base.h"
#include "Walnut/Sence/Level.h"

namespace Walnut
{
    class SceneSerializer
    {
    public:
        SceneSerializer(const Ref<Level>& level);

        void Serialize(const std::string& filepath);
        void SerializeRuntime(const std::string& filepath);

        bool Deserialize(const std::string& filepath);
        bool DeserializeRuntime(const std::string& filepath);
    private:
        Ref<Level> mLevel;
    };
}
