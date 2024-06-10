//
// Created by shake on 08/06/2024.
//

#include "Tab.h"

#include <imgui.h>
#include <iostream>

#include <utility>

Tab::Tab(std::string title) : m_Title(std::move(title)) {
    std::cout << m_Title << std::endl;
}


bool Tab::render() const {
    return ImGui::Button(m_Title.c_str());
}

const std::string& Tab::getTitle() const {
    return m_Title;
}
