#include "wnpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Plateform/OpenGL/OpenGLVertexArray.h"

namespace Walnut {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
		case RendererAPI::RendererAPIType::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
		case RendererAPI::RendererAPIType::DX11:    return nullptr;
		case RendererAPI::RendererAPIType::DX12:    return nullptr;
		}

		WN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}