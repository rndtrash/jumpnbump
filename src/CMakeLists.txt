#menu
add_subdirectory(include)
include_directories(${CMAKE_BINARY_DIR}/src/include)
include_directories(include)

if(USE_SDL)
	add_subdirectory(sdl)
endif()

add_subdirectory(game)
if(NOT PLATFORM_PSP)
	add_subdirectory(tools)
endif()
