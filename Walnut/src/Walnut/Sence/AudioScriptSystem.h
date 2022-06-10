#pragma once

#include "System.h"
#include "Level.h"

//#include <fmod.hpp>
//#include <fmod.h>

namespace Walnut
{
	class AudioScriptSystem : public System
	{
	public:
		AudioScriptSystem(Level* level);
		virtual ~AudioScriptSystem() = default;
	public:
		void OnRuntiemStart() override;
		void OnUpdateRuntime(Timestep ts) override;
		void OnRuntimeStop() override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	private:
//		FMOD::System* mFmodSystem;
//		FMOD_SYSTEM* mFmodSystem2;
	};
}