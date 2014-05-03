cmake_minimum_required(VERSION 2.8)

project(TweakUI)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
add_definitions("-DANT_OSX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
add_definitions("-DANT_UNIX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
add_definitions("-DANT_WINDOWS")
endif()

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
  ./src/TwBar.cpp
  ./src/TwColors.h
  ./src/TwMgr.cpp
  ./src/TwGraph.h
  ./src/TwFonts.cpp
  ./src/TwMgr.h
  ./src/TwPrecomp.h
  ./src/TwColors.cpp
  ./src/TwFonts.h
  ./src/TwBar.h
  ./src/TwPrecomp.cpp
  ./src/AntPerfTimer.h
  ./src/custom-widgets.h
  ./src/custom-widgets.cpp
  ./include/TweakUI.h
  ./include/TweakUI/Curve.h
)

set(TWEAKUI_LIBRARIES
  TweakUI
  PARENT_SCOPE
)

