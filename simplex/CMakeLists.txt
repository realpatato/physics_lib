add_library(simplex_lib STATIC simplex.cpp simplex.hpp)

target_include_directories(simplex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(simplex_lib
    PRIVATE
        point_lib
)