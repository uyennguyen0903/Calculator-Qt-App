cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
SET(QT_USE_QTMULTIMEDIA TRUE)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(TEST test_UTcomp)
add_executable(${TEST} UtilTest.cpp)

target_link_libraries(${TEST} Qt5::Widgets)
target_link_libraries(${TEST} Qt5::Core)
target_link_libraries(${TEST} Qt5::Gui)
target_link_libraries(${TEST} UTComp_lib)
