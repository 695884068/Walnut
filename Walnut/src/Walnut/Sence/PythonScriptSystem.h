#pragma once

#include "System.h"
#include "Level.h"

namespace Walnut
{
	class PythonScriptSystem : public System
	{
	public:
		PythonScriptSystem(Level* level);
		virtual ~PythonScriptSystem() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	private:
		bool bLoadPython = false;
	};
}