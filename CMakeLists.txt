cmake_minimum_required(VERSION 3.16)

project(JumpNBump VERSION 1.70.0)

include(GNUInstallDirs)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(DATADIR ${CMAKE_INSTALL_PREFIX}/share)
set(GAMEDATADIR ${CMAKE_INSTALL_PREFIX}/share)

option(USE_SDL "Use SDL2" ON)
if(USE_SDL)
	add_definitions(-DUSE_SDL)
endif()

option(USE_SDL_MIXER "Use SDL2_mixer" ON)
if(USE_SDL_MIXER)
	add_definitions(-DUSE_SDL_MIXER)
else()
	add_definitions(-DNO_SDL_MIXER)
endif()

option(USE_NET "Add online multiplayer" ON)
if(USE_NET)
	add_definitions(-DUSE_NET)
endif()

option(ZLIB_SUPPORT "Use zlib" ON)
if(ZLIB_SUPPORT)
	add_definitions(-DZLIB_SUPPORT)
endif()

option(BZLIB_SUPPORT "Use bzlib" ON)
if(BZLIB_SUPPORT)
	add_definitions(-DBZLIB_SUPPORT)
endif()

# Add main target
add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wno-error=unused-but-set-parameter -Wno-error=pedantic -std=gnu17)

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(dist)
