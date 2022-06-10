#include "wnpch.h"
#include "RenderCommand.h"

#include "Plateform/OpenGL/OpenGLRendererAPI.h"

namespace Walnut { 

	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
}