
cmake_minimum_required(VERSION 3.5)
project(AbseilTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(ABSL_PROPAGATE_CXX_STD ON)
add_subdirectory(abseil)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(
    QT NAMES Qt6 Qt5
    COMPONENTS Widgets Charts Svg Network
    REQUIRED)
find_package(
    Qt${QT_VERSION_MAJOR}
    COMPONENTS Widgets Charts Svg Network
    REQUIRED)

add_library(_iqt INTERFACE)
target_link_libraries(_iqt INTERFACE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Svg
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::Network
)

add_executable(
    _abseil_pet
    include/NetworkLayer/NetworkLayer.h
    src/NetworkLayer/NetworkLayer.cpp
    src/main.cpp
)

target_include_directories(_abseil_pet PRIVATE include/NetworkLayer)

target_link_libraries(_abseil_pet PUBLIC
    absl::strings
    _iqt
)
