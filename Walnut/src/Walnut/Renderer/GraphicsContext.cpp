#include "wnpch.h"

#include "GraphicsContext.h"
#include "Renderer.h"
#include "Plateform/OpenGL/OpenGLContext.h"


namespace Walnut
{
	Ref<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPI::RendererAPIType::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLContext>(static_cast<GLFWwindow*>(window));
//		case RendererAPI::RendererAPIType::Vulkan:  return CreateRef<VulkanContext>(static_cast<GLFWwindow*>(window));
//		case RendererAPI::RendererAPIType::DX11:    return CreateRef<Dx11Context>(static_cast<GLFWwindow*>(window));
		case RendererAPI::RendererAPIType::DX12:    return nullptr;
		}

		WN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}