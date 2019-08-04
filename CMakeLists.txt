cmake_minimum_required(VERSION 3.0.0)

project(canvas VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    mazelgenerator.h
    mazelgenerator.cpp
    application.h
    application.cpp
    qtcanvas.h
    qtcanvas.cpp
    )

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
