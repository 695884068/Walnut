#pragma once

#include "Walnut/Sence/ComponentBase.h"

namespace Walnut
{
    // Forward declaration
    class ScriptableEntity;
    class NativeScriptComponent : public ComponentBase
    {
    public:
        ScriptableEntity* Instance = nullptr;

        ScriptableEntity* (*InstantiateScript)();
        void(*DestroyScript)(NativeScriptComponent*);

        template<typename T>
        void Bind()
        {
            InstantiateScript = []() { return static_cast<ScriptableEntity*>(new T()); };
            DestroyScript = [](NativeScriptComponent* nsc) { delete nsc->Instance; nsc->Instance = nullptr; };
        }
    };
}