#pragma once

#include "Walnut/Sence/ComponentBase.h"

//#include <fmod.hpp>

namespace Walnut
{
    class SoundComponent : public ComponentBase
    {
    public:
        SoundComponent() = default;
        SoundComponent(const SoundComponent&) = default;
//        SoundComponent(const std::string& path)
 //           : Path(path)
//        {}

//        std::string Path = "None";
        bool Play;

 //       FMOD::Sound* Sound;
 //       FMOD::Channel* Channel = nullptr;
    };
}