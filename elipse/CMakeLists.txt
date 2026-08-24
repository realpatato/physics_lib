add_library(elipse_lib STATIC elipse.cpp elipse.hpp)

target_include_directories(elipse_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG 6.0
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE) 

FetchContent_MakeAvailable(raylib)

target_link_libraries(elipse_lib
    PRIVATE
        point_lib
        raylib
)