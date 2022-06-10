#pragma once

#include "Walnut/Asset/PublicSingleton.h"

#include <filesystem>

namespace Walnut
{
    class AssetManager final : public PublicSingleton<AssetManager>
    {
    public:
        static std::filesystem::path GetFullPath(const std::string& RelativePath);
    };
}