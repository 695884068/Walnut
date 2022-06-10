#include "wnpch.h"

#include "UniformBuffer.h"
#include "Renderer.h"
#include "Plateform/OpenGL/OpenGLUniformBuffer.h"

namespace Walnut 
{
	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPI::RendererAPIType::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
		case RendererAPI::RendererAPIType::DX11:    return nullptr;
		case RendererAPI::RendererAPIType::DX12:    return nullptr;
		}

		WN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}