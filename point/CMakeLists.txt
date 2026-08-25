add_library(point_lib STATIC point.cpp point.hpp)

target_include_directories(point_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(point_lib
    PRIVATE
        constants
)