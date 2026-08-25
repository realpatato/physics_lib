add_library(constants STATIC constants.cpp constants.hpp)

target_include_directories(constants PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})