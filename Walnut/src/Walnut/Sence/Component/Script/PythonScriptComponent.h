#pragma once

#include "Walnut/Sence/ComponentBase.h"

namespace Walnut
{
    class PythonScriptComponent : public ComponentBase
    {
    public:
        PythonScriptComponent() = default;
        PythonScriptComponent(const PythonScriptComponent&) = default;
        PythonScriptComponent(const std::string& path)
            : Path(path)
        {}

        std::string Path;
        static bool UseScript;
    };
}