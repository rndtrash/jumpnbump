add_library(sdl STATIC "")

find_package(SDL2 REQUIRED)

set(SDL_HEADERS
	filter.h
)

set(SDL_SOURCES
	filter.c
	gfx.c
	input.c
	interrpt.c
	sound.c
)

target_sources(sdl
	PRIVATE
		${SDL_HEADERS}
		${SDL_SOURCES}
)

target_link_libraries(sdl
	PUBLIC
		SDL2::Core
		SDL2::Main
)

if(USE_SDL_MIXER)
	find_package(SDL2_mixer REQUIRED)
	target_link_libraries(sdl
		PUBLIC
			SDL2::Mixer
	)
endif()
