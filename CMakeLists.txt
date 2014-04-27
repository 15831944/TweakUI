cmake_minimum_required(VERSION 2.8)

project(TweakUI)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
add_definitions("-D_UNIX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
add_definitions("-D_UNIX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
add_definitions("-DANT_WINDOWS")
endif()

find_package(OpenGL REQUIRED)

include_directories(
  ./include
)

include_directories(
  SYSTEM
  ${OPENGL_INCLUDE_DIR}
)

if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
set(WARNING_FLAGS "-w")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${WARNING_FLAGS}")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL CLANG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")
if(APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()
endif()

add_library(TweakUI STATIC
  ./src/LoadOGL.cpp
  ./src/TwBar.cpp
  ./src/TwColors.h
  ./src/resource.h
  ./src/TwOpenGL.cpp
  ./src/TwOpenGL.h
  ./src/TwMgr.cpp
  ./src/TwGraph.h
  ./src/TwFonts.cpp
  ./src/TwMgr.h
  ./src/TwPrecomp.h
  ./src/TwColors.cpp
  ./src/TwFonts.h
  ./src/LoadOGL.h
  ./src/LoadOGLCore.cpp
  ./src/TwOpenGLCore.h
  ./src/TwBar.h
  ./src/res/TwXCursors.h
  ./src/LoadOGLCore.h
  ./src/TwOpenGLCore.cpp
  ./src/TwPrecomp.cpp
  ./src/AntPerfTimer.h
  ./include/AntTweakBar.h
)

set(TWEAKUI_LIBRARIES
  TweakUI
  ${OPENGL_gl_LIBRARY}
  ${X11_X11_LIB}
  PARENT_SCOPE
)

