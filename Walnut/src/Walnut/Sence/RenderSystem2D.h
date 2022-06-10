#pragma once

#include "System.h"
#include "Level.h"

namespace Walnut
{
	class RenderSystem2D : public System
	{
	public:
		RenderSystem2D(Level* level) : System(level) {}
		virtual ~RenderSystem2D() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	};
}
