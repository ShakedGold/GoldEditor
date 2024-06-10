//
// Created by shake on 08/06/2024.
//

#include "Workspace.h"

#include <imgui.h>

Workspace::Workspace(const std::string& title)
    : m_Title(title), m_BufferSize(2048), m_Buffer(new char[m_BufferSize]) {
  m_Buffer[0] = '\0';
}
Workspace::~Workspace() { delete m_Buffer; }

void Workspace::render() {
  // read file contents from Path
  std::FILE* file = std::fopen(Path.c_str(), "r");
  if (file) {
    std::fseek(file, 0, SEEK_END);
    long length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    if (length < m_BufferSize) {
      std::fread(m_Buffer, 1, length, file);
      m_Buffer[length] = '\0';
    }
    std::fclose(file);
  }

  ImGui::SetNextWindowDockID(ImGui::GetMainViewport()->ID,
                             ImGuiCond_FirstUseEver);
  if (ImGui::BeginTabItem(m_Title.c_str())) {
    ImVec2 availableSize =
        ImGui::GetContentRegionAvail();  // Get available space

    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGuiCol_WindowBg);
    ImGui::InputTextMultiline("##", m_Buffer, m_BufferSize, availableSize);
    ImGui::PopStyleColor();

    ImGui::EndTabItem();
  }
}