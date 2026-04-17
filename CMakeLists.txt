cmake_minimum_required(VERSION 4.0)

project(ludum_dare_59)

add_subdirectory(3rdparty/raylib)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB IMGUI_SOURCES CONFIGURE_DEPENDS 3rdparty/imgui/imgui*.cpp)
set(RLIMGUI_SOURCES
    3rdparty/rlImGui/rlImGui.cpp
)
add_executable(ld59 ${SOURCES} ${IMGUI_SOURCES} ${RLIMGUI_SOURCES})

target_include_directories(ld59 PRIVATE src/ 3rdparty/sokol/ 3rdparty/sokol/util/ 3rdparty/imgui/ 3rdparty/implot/ 3rdparty/implot3d/ 3rdparty/rlImGui/)

target_link_libraries(ld59 PRIVATE raylib)

if(EMSCRIPTEN)
   set(CMAKE_EXECUTABLE_SUFFIX ".html")
   target_link_options(ld59 PRIVATE
        "-sUSE_WEBGPU=1"
        "-O1" #Comment out for release builds
        "-sWASM_BIGINT" # Comment 
        # "-sUSE_WEBGL2=1" 
        "-sWASM=1"
        "-sASYNCIFY=1"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sASSERTIONS=1"
#        "-sDISABLE_EXCEPTION_CATCHING=1"
#        "-sNO_FILESYSTEM=1"
        "--shell-file=${CMAKE_CURRENT_LIST_DIR}/src/minimal_shell.html"
   )
endif()