#include <Walnut.h>

#include "Plateform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Walnut::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Walnut::VertexArray::Create());


		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Walnut::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Walnut::VertexBuffer::Create(vertices, sizeof(vertices)));

		Walnut::BufferLayout layout = {
			{ Walnut::ShaderDataType::Float3, "a_Position" },
			{ Walnut::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<Walnut::IndexBuffer> indexBuffer;
		indexBuffer.reset(Walnut::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Walnut::VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<Walnut::VertexBuffer> squareVB;
		squareVB.reset(Walnut::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Walnut::ShaderDataType::Float3, "a_Position" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Walnut::IndexBuffer> squareIB;
		squareIB.reset(Walnut::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
				
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Walnut::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			
			uniform vec3 u_Color;
			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader.reset(Walnut::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));
	}

	void OnUpdate(Walnut::Timestep ts) override
	{
		if (Walnut::Input::IsKeyPressed(WN_KEY_LEFT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		else if (Walnut::Input::IsKeyPressed(WN_KEY_RIGHT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		if (Walnut::Input::IsKeyPressed(WN_KEY_UP))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		else if (Walnut::Input::IsKeyPressed(WN_KEY_DOWN))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (Walnut::Input::IsKeyPressed(WN_KEY_A))
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		else if (Walnut::Input::IsKeyPressed(WN_KEY_D))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		Walnut::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Walnut::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Walnut::Renderer::BeginScene(m_Camera);
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
		std::dynamic_pointer_cast<Walnut::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Walnut::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Walnut::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		Walnut::Renderer::Submit(m_Shader, m_VertexArray);
		Walnut::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Walnut::Event& event) override
	{
	}
private:
	std::shared_ptr<Walnut::Shader> m_Shader;
	std::shared_ptr<Walnut::VertexArray> m_VertexArray;

	std::shared_ptr<Walnut::Shader> m_FlatColorShader;
	std::shared_ptr<Walnut::VertexArray> m_SquareVA;

	Walnut::OrthographicCamera m_Camera;

	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.38f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 68.0f;


	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sanbox : public Walnut::Application
{
public:
	Sanbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sanbox()
	{
	}
};

Walnut::Application* Walnut::CreateApplication()
{
	return new Sanbox();
}