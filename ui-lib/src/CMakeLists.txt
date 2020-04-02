file(GLOB_RECURSE UI_FILES *.ui)
file(GLOB_RECURSE SRC_FILES *.cpp)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})
# TODO: its better to be moved to 'res' directory
qt5_add_resources(RES_FILES ../res/resources.qrc)

add_library(${CMAKE_PROJECT_NAME} WIN32
  ${UI_HEADERS}
  ${SRC_FILES}
  ${RES_FILES}
)

target_include_directories(${CMAKE_PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>    
)

target_link_libraries(${CMAKE_PROJECT_NAME}
  PUBLIC
    Qt5::Widgets
)
