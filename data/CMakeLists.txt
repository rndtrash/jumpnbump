set(GOBS
	font.gob numbers.gob objects.gob rabbit.gob
)

list(TRANSFORM GOBS PREPEND ${CMAKE_CURRENT_BINARY_DIR}/)

set(DATAFILES
	bump.mod calib.dat death.smp fly.smp jump.mod
	jump.smp levelmap.txt level.pcx mask.pcx menu.pcx
	menumask.pcx scores.mod splash.smp spring.smp
)

list(TRANSFORM DATAFILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

add_custom_command(
	OUTPUT font.gob
	COMMAND gobpack -o ${CMAKE_CURRENT_BINARY_DIR}/font.gob ${CMAKE_CURRENT_SOURCE_DIR}/font
	DEPENDS gobpack font.pcx font.txt
	VERBATIM
)

add_custom_command(
	OUTPUT rabbit.gob
	COMMAND gobpack -o ${CMAKE_CURRENT_BINARY_DIR}/rabbit.gob ${CMAKE_CURRENT_SOURCE_DIR}/rabbit
	DEPENDS gobpack rabbit.pcx rabbit.txt
	VERBATIM
)

add_custom_command(
	OUTPUT numbers.gob
	COMMAND gobpack -o ${CMAKE_CURRENT_BINARY_DIR}/numbers.gob ${CMAKE_CURRENT_SOURCE_DIR}/numbers
	DEPENDS gobpack numbers.pcx numbers.txt
	VERBATIM
)

add_custom_command(
	OUTPUT objects.gob
	COMMAND gobpack -o ${CMAKE_CURRENT_BINARY_DIR}/objects.gob ${CMAKE_CURRENT_SOURCE_DIR}/objects
	DEPENDS gobpack objects.pcx objects.txt
	VERBATIM
)

add_custom_command(
	OUTPUT jumpnbump.dat
	COMMAND jnbpack -o jumpnbump.dat ${DATAFILES} ${GOBS}
	DEPENDS jnbpack ${DATAFILES} ${GOBS}
	VERBATIM
)

install(FILES jumpnbump.dat DESTINATION ${GAMEDATADIR}/jumpnbump)

add_custom_target(data ALL
	DEPENDS jumpnbump.dat)
