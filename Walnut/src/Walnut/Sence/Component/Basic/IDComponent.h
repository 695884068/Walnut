#pragma once

#include "Walnut/Sence/ComponentBase.h"
#include "Walnut/Core/UUID.h"

namespace Walnut
{
	class IDComponent : public ComponentBase
	{
	public:
		UUID ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
		IDComponent(const UUID& id)
			: ID(id)
		{
		}
	};
}