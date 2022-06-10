#include "wnpch.h"

#include "Renderer.h"
#include "Renderer2D.h"
#include "Renderer3D.h"
#include "Plateform/OpenGL/OpenGLShader.h"
#include "PostProcessing.h"

#include "Walnut/Core/Application.h"

namespace Walnut
{
    Renderer::SceneData* Renderer::mSceneData = new Renderer::SceneData;

    void Renderer::Init()
    {
        RenderCommand::Init();
        Renderer3D::Init();
        Renderer2D::Init();
        PostProcessing::Init();
    }

    void Renderer::Shutdown()
    {
        Renderer2D::Shutdown();
        Renderer3D::Shutdown();
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
        RenderCommand::SetViewport(0, 0, width, height);
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
    {
        shader->Bind();
        std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", mSceneData->ViewProjectionMatrix);
        std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }

    Ref<GraphicsContext> Renderer::GetContext()
    {
        return Application::GetInstance().GetWindow().GetGraphicsContext();
    }
}
