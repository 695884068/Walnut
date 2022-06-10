#pragma once

#include "Walnut/Sence/ComponentBase.h"
#include "Walnut/Renderer/Texture.h"

#include <glm/glm.hpp>

namespace Walnut
{
	class SpriteRendererComponent : public ComponentBase
	{
	public:
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
		Ref<Texture2D> Texture;
		float TilingFactor = 1.0f;

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4 & color)
			: Color(color) {}
	};
}