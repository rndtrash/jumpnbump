add_executable(jumpnbump)

install(TARGETS jumpnbump DESTINATION ${CMAKE_INSTALL_BINDIR})

set(JNB_HEADERS
	network.h
)

set(JNB_SOURCES
	main.c
	filter.c
	menu.c
	network.c
)

target_sources(jumpnbump
	PRIVATE
		${JNB_SOURCES}
		${JNB_HEADERS}
)

target_compile_features(jumpnbump
	PRIVATE
		c_std_17
)

target_link_libraries(jumpnbump
	PRIVATE
		sdl
		m
)

target_include_directories(jumpnbump
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)


if(USE_NET)
	find_package(SDL2_net REQUIRED)
	target_link_libraries(jumpnbump
		PRIVATE
			SDL2::Net
	)
endif()

if(BZLIB_SUPPORT)
	find_package(BZip2 REQUIRED)
	target_include_directories(jumpnbump
		PRIVATE
			${BZIP2_INCLUDE_DIR}
	)
	target_link_libraries(jumpnbump
		PRIVATE
			${BZIP2_LIBRARIES}
	)
endif()

if(ZLIB_SUPPORT)
	find_package(ZLIB REQUIRED)
	target_include_directories(jumpnbump
		PRIVATE
			${ZLIB_INCLUDE_DIR}
	)
	target_link_libraries(jumpnbump
		PRIVATE
			${ZLIB_LIBRARIES}
	)
endif()

