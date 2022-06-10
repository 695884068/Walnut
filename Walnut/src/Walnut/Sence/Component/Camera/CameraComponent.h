#pragma once

#include "Walnut/Sence/ComponentBase.h"
#include "Walnut/Renderer/SceneCamera.h"

namespace Walnut
{
	class CameraComponent : public ComponentBase
	{
	public:
        SceneCamera Camera;
        bool Primary = true; // TODO: think about moving to Scene
        bool FixedAspectRatio = false;

        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
	};
}