#pragma once

#include "Walnut/Core/Timestep.h"
#include "Level.h"
#include "Walnut/Renderer/EditorCamera.h"

namespace Walnut
{
    class System
    {
    public:
        System() = delete;
        System(Level* level) : mLevel(level) {}
        virtual ~System() = default;
    public:
        virtual void OnUpdateEditor(Timestep ts, EditorCamera& camera) {};
        virtual void OnUpdateRuntime(Timestep ts) {}
        virtual void OnRuntiemStart() {}
        virtual void OnRuntimeStop() {}
    protected:
        Level* mLevel = nullptr;
    };
}