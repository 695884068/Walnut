#pragma once

#include "ComponentBase.h"
#include "Component/MeshComponent.h" 

#include "Component/Basic/IDComponent.h"
#include "Component/Basic/TagComponent.h"
#include "Component/Camera/CameraComponent.h"
#include "Component/Physics/2D/BoxCollider2DComponent.h"
#include "Component/Physics/2D/CircleCollider2DComponent.h"
#include "Component/Physics/2D/Rigidbody2DComponent.h"
#include "Component/Physics/3D/BoxCollider3DComponent.h"
#include "Component/Physics/3D/SphereCollider3DComponent.h"
#include "Component/Physics/3D/Rigidbody3DComponent.h"
#include "Component/Physics/3D/ConvexHullComponent.h"
#include "Component/Script/NativeScriptComponent.h"
#include "Component/Script/PythonScriptComponent.h"
#include "Component/Shape/CircleRendererComponent.h"
#include "Component/Shape/SpriteRendererComponent.h"
#include "Component/Transform/TransformComponent.h" 
#include "Component/Light/PointLightComponent.h"
#include "Component/Light/DirectionalLightComponent.h"
#include "Component/Audio/SoundComponent.h"


#include <type_traits>
//#include <concepts>

namespace Walnut
{
    // Every Component Class should be registered in this file

    template<class T>
//    concept Component = std::is_base_of_v<ComponentBase, T>;

 //   template<Component... C>
    struct ComponentGroup
    {

    };

    /*  using AllComponents = ComponentGroup<TransformComponent, CircleRendererComponent, SpriteRendererComponent,
        CameraComponent, NativeScriptComponent, PythonScriptComponent, 
        Rigidbody2DComponent, BoxCollider2DComponent, CircleCollider2DComponent, 
        Rigidbody3DComponent, SphereCollider3DComponent, BoxCollider3DComponent, ConvexHullComponent,
        MeshComponent, PointLightComponent, DirectionalLightComponent,
        SoundComponent>;*/
}