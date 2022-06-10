#pragma once

#include "Walnut/Sence/ComponentBase.h"
#include "Walnut/Asset/Mesh/Mesh.h"

#include <filesystem>

namespace Walnut
{
    class MeshComponent : public ComponentBase
    {
    public:
		MeshComponent() { mMesh = CreateRef<Mesh>(); };
		MeshComponent(const MeshComponent&) = default;
		MeshComponent(const std::string & path)
			: Path(path), mMesh(CreateRef<Mesh>(path))
		{
		}
		//MeshComponent(const std::filesystem::path& path)
		//	: Path(path)
		//{
		//}

		std::string Path = "None";
		Ref<Mesh> mMesh;
    };
}