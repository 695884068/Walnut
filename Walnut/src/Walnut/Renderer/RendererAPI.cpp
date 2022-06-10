#include "wnpch.h"
#include "Walnut/Renderer/RendererAPI.h"

#include "Plateform/OpenGL/OpenGLRendererAPI.h"

namespace Walnut {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    WN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		WN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}