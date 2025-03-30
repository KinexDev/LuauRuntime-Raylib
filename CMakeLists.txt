cmake_minimum_required(VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("raylib-luau")

add_subdirectory(thirdparty/luau)

set(RAYLIB_VERSION 5.5)

find_package(raylib ${RAYLIB_VERSION} QUIET)

if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
  endif()
endif()

add_library(raylib-luau SHARED "LuauRaylib.cpp"     "LuauRaylib.h")

target_link_libraries(raylib-luau PRIVATE Luau.VM Luau.Compiler raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET raylib-luau PROPERTY CXX_STANDARD 20)
endif()

if (APPLE)
    target_link_libraries(raylib-luau "-framework IOKit")
    target_link_libraries(raylib-luau "-framework Cocoa")
    target_link_libraries(raylib-luau "-framework OpenGL")
endif()

if (${PLATFORM} STREQUAL "Web")
    set_target_properties(raylib-luau PROPERTIES SUFFIX ".html")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()

