#pragma once

#include "System.h"
#include "Level.h"
#include "Walnut/Renderer/UniformBuffer.h"

namespace Walnut
{
	struct EnvironmentHdrSettings
	{
		float SkyBoxLod = 0.0f;
		float exposure = 1.0f;
	};

	class EnvironmentSystem : public System
	{
	public:
		EnvironmentSystem(Level* level) : System(level) {}
		virtual ~EnvironmentSystem() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	public:
		static EnvironmentHdrSettings environmentSettings;
	private:
		void DrawSkyBox(const glm::mat4& ViewMatrix, const glm::mat4& ProjectMatrix);
		void DrawEnvironmentHdr(const glm::mat4& ViewMatrix, const glm::mat4& ProjectMatrix);
	};
}
