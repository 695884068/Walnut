#pragma once

#include "Walnut/Core/Base.h"
#include "Walnut/Sence/Level.h"
#include "Walnut/Sence/Entity.h"

namespace Walnut
{
    class SceneHierarchyPanel
    {
    public:
        SceneHierarchyPanel() = default;
        SceneHierarchyPanel(const Ref<Level>& context);

        void SetContext(const Ref<Level>& context);

        void OnImGuiRender(bool* pOpen, bool* pOpenProperties);

		Entity GetSelectedEntity() const { return mSelectionContext; }
		void SetSelectedEntity(Entity entity);
    private:
        void DrawEntityNode(Entity entity);
        void DrawComponents(Entity entity);
    private:
        Ref<Level> mContext;
        Entity mSelectionContext;
    };
}
