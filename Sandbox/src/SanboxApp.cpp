#include <Walnut.h>

#include "Plateform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Walnut
{
	void MyAppInitialize(Application& app)
	{
		app.Init("Walnut Editor");
		app.PushLayer(new EditorLayer());
	}
}