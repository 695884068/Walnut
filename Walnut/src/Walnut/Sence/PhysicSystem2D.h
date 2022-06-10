#pragma once

#include "System.h"
#include "Level.h"

namespace Walnut
{
    class PhysicSystem2D : public System
    {
	public:
		PhysicSystem2D(Level* level) : System(level) {}
		virtual ~PhysicSystem2D() = default;
    public:
		void OnRuntiemStart() override;
		void OnUpdateRuntime(Timestep ts) override;
		void OnRuntimeStop() override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	private:
		class b2World* mPhysicsWorld = nullptr;
    };
}