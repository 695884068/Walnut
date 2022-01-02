#include "wnpch.h"
#include "RenderCommand.h"

#include "Plateform/OpenGL/OpenGLRendererAPI.h"

namespace Walnut { 

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}