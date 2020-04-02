cmake_minimum_required(VERSION 3.15)

project(window)
set(PROJECT_LONGNAME "Window")
set(PROJECT_VERSION "1.0.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Configure Qt
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

# this probably should be handled at toplevel
if (NOT MSVC)
  # Enable the C++11 standard
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()

file(GLOB_RECURSE UI_FILES src/*.ui)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})
# TODO: its better to be moved to 'res' directory
qt5_add_resources(RES_FILES res/resources.qrc)

add_library(${CMAKE_PROJECT_NAME}
  ${UI_HEADERS}
  ${SRC_FILES}
  ${RES_FILES}
)

target_include_directories(${CMAKE_PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/src    
)

target_link_libraries(${CMAKE_PROJECT_NAME}
  PUBLIC
    Qt5::Widgets
)

# export target library as alias
add_library(Project::Lib ALIAS ${CMAKE_PROJECT_NAME})
