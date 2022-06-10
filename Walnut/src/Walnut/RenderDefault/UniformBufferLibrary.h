#pragma once 

#include "Walnut/Renderer/UniformBuffer.h"
#include "Library.h"

#include <glm/glm.hpp>

namespace Walnut
{
    struct CameraData
    {
        glm::mat4 ViewProjection;
    };

    template<>
    class Library<UniformBuffer> : public LibraryBase<Library, UniformBuffer>
    {
    public:
        Library();

        Ref<UniformBuffer> GetCameraUniformBuffer();
    };
}