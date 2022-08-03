#menu
add_subdirectory(include)
include_directories(${CMAKE_BINARY_DIR}/src/include)
include_directories(include)

if(USE_SDL)
	add_subdirectory(sdl)
endif()

add_subdirectory(game)
add_subdirectory(tools)
