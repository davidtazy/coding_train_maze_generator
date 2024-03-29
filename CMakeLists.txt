cmake_minimum_required(VERSION 3.0.0)

project(canvas VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    maze_generator.h
    maze_generator.cpp
    application.h
    application.cpp
    qtcanvas.h
    qtcanvas.cpp
    mazeapplication.h
    mazeapplication.cpp
    )

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

option (BUILD_TESTING "build test" ON)

if(BUILD_TESTING)
    enable_testing()
    find_package(Qt5Test REQUIRED)
    add_executable(test_generator
        test/test_generator.cpp
        maze_generator.h
        maze_generator.cpp
        application.h)
    target_link_libraries(test_generator Qt5::Test)
    add_test(test_generator test_generator)
endif()
