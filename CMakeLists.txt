cmake_minimum_required(VERSION 3.28)
project(Golditor)

set(CMAKE_CXX_STANDARD 26)
set(SOURCE_FILES main.cpp)

set(IMGUI_PATH "imgui")

file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})

add_executable(Golditor ${SOURCE_FILES})
