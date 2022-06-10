#pragma once

#include <glm/glm.hpp>

#include "Walnut/Core/KeyCodes.h"
#include "Walnut/Core/MouseCodes.h"

namespace Walnut {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
