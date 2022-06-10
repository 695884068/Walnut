#include "wnpch.h"
#include "ModeManager.h"

namespace Walnut
{
    int ModeManager::b3DMode = 1;
    bool ModeManager::bHdrUse = false;
    bool ModeManager::bEditState = true;
    SceneMode ModeManager::mSceneMode = SceneMode::None;
    EditMode ModeManager::mEditMode = EditMode::Select;
    bool ModeManager::bShowPhysicsColliders = false;
    PhysicsDebugDrawModeFlag ModeManager::mPhysicsDebugDrawModeFlag = PhysicsDebugDrawModeFlag::HEngine_DrawWireframe;
}