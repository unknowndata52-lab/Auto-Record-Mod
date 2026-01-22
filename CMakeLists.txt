cmake_minimum_required(VERSION 3.13)

find_package(Geode REQUIRED)
project(SmartRecorder)

add_geode_mod(
    ${Auto_Record}
    SOURCES src/main.cpp
)
