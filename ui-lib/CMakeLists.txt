cmake_minimum_required(VERSION 3.15)

project(window VERSION 1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Configure Qt
find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE UI_FILES src/*.ui)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_library(${CMAKE_PROJECT_NAME}
  ${UI_FILES}
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
