add_executable(glorius_use_log
	glorious_use_log.cpp)

add_dependencies(glorius_use_log
		glor_system)

if (CYGWIN OR APPLE)
target_link_libraries(glorius_use_log
	glor_system
	pthread
	${Boost_SYSTEM_LIBRARY})
else()
target_link_libraries(glorius_use_log
	glor_system
	rt
	pthread
	${Boost_SYSTEM_LIBRARY})
endif()
