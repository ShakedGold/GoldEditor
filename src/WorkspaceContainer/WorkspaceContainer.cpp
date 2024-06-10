//
// Created by shake on 08/06/2024.
//

#include "WorkspaceContainer.h"

#include <imgui.h>
#include <imgui_internal.h>

void WorkspaceContainer::render() {
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
    ImGui::SetNextWindowClass(&window_class);
    ImGui::Begin("##WorkspaceContainer");

    ImGui::BeginTabBar("##WorkspaceContainer/TabBar");
    for (auto& [_, workspace] : Workspaces) {
        workspace->render();
    }
    ImGui::EndTabBar();

    // End the window
    ImGui::End();
}

