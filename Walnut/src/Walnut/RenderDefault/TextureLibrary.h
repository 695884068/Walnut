#pragma once 

#include "Walnut/Renderer/Texture.h"
#include "Library.h"

namespace Walnut
{
    template<>
    class Library<Texture2D> : public LibraryBase<Library, Texture2D>
    {
    public:
        Library();

        [[nodiscard]] Ref<Texture2D> GetDefaultTexture();
        [[nodiscard]] Ref<Texture2D> GetWhiteTexture();
    };
}