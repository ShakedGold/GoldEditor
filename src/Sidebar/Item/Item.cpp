//
// Created by shake on 08/06/2024.
//

#include "Item.h"

#include <imgui.h>
#include <iostream>

Item::Item(const std::string &name) : m_Name(name), IsFocused(false) {}

void Item::render() {
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1, 1, 1, static_cast<float>(IsFocused) * 0.2f));
    ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 0.0f));
    if(ImGui::Button(m_Name.c_str(), ImVec2(ImGui::GetWindowSize().x, 25.0f))) {
        if(OnClick) {
            OnClick();
        }
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
}

std::string Item::getName() const {
    return m_Name;
}

void Item::setName(const std::string &name) {
    m_Name = name;
}

