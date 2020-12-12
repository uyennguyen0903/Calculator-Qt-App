cmake_minimum_required(VERSION 3.5)
# get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# string(REPLACE " " "_" ProjectId UTCalculateur)
project(UTCalculateur VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
SET(QT_USE_QTMULTIMEDIA TRUE)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
# find_package(Qt5Multimedia REQUIRED)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(UTCalculateur ${all_SRCS})

target_link_libraries(UTCalculateur Qt5::Widgets)
target_link_libraries(UTCalculateur Qt5::Core)
target_link_libraries(UTCalculateur Qt5::Gui)
# target_link_libraries(UTCalculateur Qt5Multimedia)
# target_link_libraries(UTCalculateur Qt5::Multimedia)

add_library(UTComp_lib ${all_SRCS})
target_link_libraries(UTComp_lib Qt5::Widgets)
target_link_libraries(UTComp_lib Qt5::Core)
target_link_libraries(UTComp_lib Qt5::Gui)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(test)