cmake_minimum_required(VERSION 4.0)

project(ludum_dare_59)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB IMGUI_SOURCES CONFIGURE_DEPENDS 3rdparty/imgui/imgui*.cpp)
add_executable(ld59 ${SOURCES} ${IMGUI_SOURCES})
target_include_directories(ld59 PRIVATE src/ 3rdparty/sokol/ 3rdparty/sokol/util/ 3rdparty/imgui/)
target_link_libraries(ld59)


if(WIN32)
   target_compile_definitions(ld59 PRIVATE SOKOL_D3D11=1)
elseif(EMSCRIPTEN)
   set(CMAKE_EXECUTABLE_SUFFIX ".html")
   target_compile_definitions(ld59 PRIVATE SOKOL_WGPU=1)
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