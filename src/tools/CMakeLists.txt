add_executable(gobpack)

target_compile_features(gobpack
	PRIVATE
		c_std_17
)

target_sources(gobpack
	PRIVATE
		gobpack.c
)

install(TARGETS gobpack DESTINATION ${CMAKE_INSTALL_BINDIR})

###

add_executable(jnbpack)

target_compile_features(gobpack
	PRIVATE
		c_std_17
)

target_sources(jnbpack
	PRIVATE
		jnbpack.c
)

install(TARGETS jnbpack DESTINATION ${CMAKE_INSTALL_BINDIR})

###

add_executable(jnbunpack)

target_compile_features(gobpack
	PRIVATE
		c_std_17
)

target_sources(jnbunpack
	PRIVATE
		jnbunpack.c
)

install(TARGETS jnbunpack DESTINATION ${CMAKE_INSTALL_BINDIR})
