cmake_minimum_required(VERSION 3.13)

# Add this line to tell CMake where Geode is located
list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})

project(MyMod)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    SOURCES main.cpp
)
