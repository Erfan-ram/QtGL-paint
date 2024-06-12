cmake_minimum_required(VERSION 3.20.1)

project(mine_painter)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(SOURCES
    src/main.cpp
    src/painter.cpp
    src/opengl.cpp
)

set(HEADERS
    include/painter.hpp
    include/opengl.hpp
)

add_executable(mine_painter ${SOURCES} ${HEADERS})

target_include_directories(mine_painter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mine_painter PRIVATE
    Qt5::Widgets
    GL
)
