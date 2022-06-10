#include "wnpch.h"

#include "Framebuffer.h"
#include "Renderer.h"

#include "Plateform/OpenGL/OpenGLFramebuffer.h"

namespace Walnut
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        WN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}