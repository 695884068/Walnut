#pragma once

#include "Walnut/Sence/ComponentBase.h"

#include <glm/glm.hpp>

namespace Walnut
{
	class ConvexHullComponent : public ComponentBase
	{
	public:
		glm::vec3 Size = { 1.0f, 1.0f, 1.0f };

		float linearDamping = 0.0f;
		float angularDamping = 0.0f;
		float restitution = 1.0f;
		float friction = 1.0f;

		ConvexHullComponent() = default;
		ConvexHullComponent(const ConvexHullComponent&) = default;
	};
}