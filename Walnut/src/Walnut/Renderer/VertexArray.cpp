#include "wnpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Plateform/OpenGL/OpenGLVertexArray.h"

namespace Walnut {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}

		WN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}