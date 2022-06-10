#include "wnpch.h"
#include "AssetManager.h"
#include "ConfigManager.h"

namespace Walnut
{
    std::filesystem::path AssetManager::GetFullPath(const std::string& RelativePath)
    {
        return ConfigManager::GetInstance().GetRootFolder() / RelativePath;
    }
}