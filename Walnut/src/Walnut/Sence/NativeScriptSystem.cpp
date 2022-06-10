#include "wnpch.h"

#include "NativeScriptSystem.h"
#include "Entity.h"
#include "Walnut/Sence/Component/Script/NativeScriptComponent.h"
#include "ScriptableEntity.h"

namespace Walnut
{
	void NativeScriptSystem::OnUpdateRuntime(Timestep ts)
	{
		mLevel->mRegistry.view<NativeScriptComponent>().each([=](auto entity, auto& nsc)  // nsc: native script component
			{
				// TODO: Move to Level::OnScenePlay
				if (!nsc.Instance)
				{
					nsc.Instance = nsc.InstantiateScript();
					nsc.Instance->mEntity = Entity{ entity, mLevel };
					nsc.Instance->OnCreate();
				}

				nsc.Instance->OnUpdate(ts);
			});
	}
}