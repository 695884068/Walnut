#pragma once

#include "System.h"
#include "Level.h"

namespace Walnut
{
	class NativeScriptSystem : public System
	{
	public:
		NativeScriptSystem(Level* level) : System(level) {}
		virtual ~NativeScriptSystem() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
	};
}