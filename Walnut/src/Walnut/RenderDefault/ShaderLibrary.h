#pragma once

#include "Walnut/Renderer/Shader.h"
#include "Library.h"

namespace Walnut
{
    template<>
    class Library<Shader> : public LibraryBase<Library, Shader>
    {
    public:
        Library();

        Ref<Shader> GetDefaultShader();
        Ref<Shader> GetSkyBoxShader();
    };
}