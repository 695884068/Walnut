#include "wnpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

Walnut::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
	WN_CORE_ASSERT(windowHandle, "Window handle is null!");
}

void Walnut::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	WN_CORE_ASSERT(status, "Failed to initialize Glad!");

	WN_CORE_INFO("OpenGL Info:");
	WN_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
	WN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
	WN_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
}

void Walnut::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
