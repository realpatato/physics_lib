cmake_minimum_required(VERSION 3.0.0)

project(physics_lib)

add_executable(physics_test)

target_sources(physics_test
    PRIVATE
        main.cpp
)