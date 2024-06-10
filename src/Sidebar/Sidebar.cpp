//
// Created by shake on 08/06/2024.
//

#include "Sidebar.h"

#include <imgui.h>
#include <imgui_internal.h>

Sidebar::Sidebar(const std::string& title) : m_Title(title) {}

void Sidebar::render() const {
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
  ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
  ImGuiWindowClass window_class;
  window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin(m_Title.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar);

  for (auto& item : m_Items) {
    item->render();
  }

  ImGui::PopStyleVar(2);
  ImGui::End();
}

void Sidebar::addItem(Item& item) {
  m_Items.emplace_back(std::make_unique<Item>(item));
}
