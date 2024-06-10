cmake_minimum_required(VERSION 3.28)
project(GoldEditor)

set(CMAKE_CXX_STANDARD 26)
set(SOURCE_FILES main.cpp
        src/Workspace/Workspace.cpp
        src/Workspace/Workspace.h
        src/Sidebar/Item/Item.cpp
        src/Sidebar/Item/Item.h
        src/Sidebar/Sidebar.cpp
        src/Sidebar/Sidebar.h
        src/WorkspaceContainer/WorkspaceContainer.cpp
        src/WorkspaceContainer/WorkspaceContainer.h
        src/Workspace/Tab/Tab.cpp
        src/Workspace/Tab/Tab.h)

# IMGUI
set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/external/imgui)

file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp ${IMGUI_PATH}/backends/*glfw.cpp ${IMGUI_PATH}/backends/*opengl3.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH}/backends)

# GLFW
set(GLFW_DIR ${CMAKE_CURRENT_LIST_DIR}/external/glfw)
add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

add_executable(GoldEditor ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
target_link_libraries(GoldEditor "ImGui")

# OPENGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})