#pragma once

#include "EditorCamera.h"
#include "Walnut/Sence/Component/MeshComponent.h"
#include "Texture.h"

namespace Walnut
{
    class Renderer3D
    {
    public:
        static void Init();
        static void Shutdown();

        static void DrawModel(const glm::mat4& transform, const glm::vec3& cameraPos, MeshComponent& MeshComponent, int EntityID);

        static void BeginScene(const Camera& camera, const glm::mat4& transform);
        static void BeginScene(const EditorCamera& camera);
        static void EndScene();
    public:
        // shadow pass
        static Ref<class Framebuffer> lightFBO;
    };
}