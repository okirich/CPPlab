cmake_minimum_required(VERSION 3.5)

project(CarFinder LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#set(PROJECT_SOURCES
#        main.cpp
#        mainwindow.cpp
#        mainwindow.h
#        mainwindow.ui
#)

file(GLOB_RECURSE PROJECT_SOURCES
        "*.h"
        "*.cpp"
        "*.ui"
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CarFinder
        ${PROJECT_SOURCES}
    )

endif()

target_link_libraries(CarFinder PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
