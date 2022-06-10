#include "wnpch.h"
#include "Entity.h"
#include "Walnut/Sence/Component/Basic/IDComponent.h"
#include "Walnut/Sence/Component/Basic/TagComponent.h"

namespace Walnut
{
    Entity::Entity(entt::entity handle, Level* level)
        : mEntityHandle(handle), mLevel(level)
    {
        //AddComponent<IDComponent>(UUID());
    }

    UUID Entity::GetUUID() { return GetComponent<IDComponent>().ID; }
    const std::string& Entity::GetName() { return GetComponent<TagComponent>().Tag; }
}