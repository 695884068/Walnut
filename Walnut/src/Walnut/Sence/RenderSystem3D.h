#pragma once

#include "System.h"
#include "Level.h"

namespace Walnut
{
	class RenderSystem3D : public System
	{
	public:
		RenderSystem3D(Level* level) : System(level) {}
		virtual ~RenderSystem3D() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	};
}
