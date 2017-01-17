add_executable(glorius_use_log
	glorious_use_log.cpp)

add_dependencies(glorius_use_log
		glor_system)

if (CYGWIN OR APPLE)
	target_link_libraries(glorius_use_log
		glor_system
		pthread
		${Boost_SYSTEM_LIBRARY})
elseif(MSVC)
	target_link_libraries(glorius_use_log
		glor_system
		${Boost_SYSTEM_LIBRARY})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DWIN32 /D_WINDOWS /W3 /GR /EHsc /MDd -DRELEASEMODE=1")
else()
	target_link_libraries(glorius_use_log
		glor_system
		rt
		pthread
		${Boost_SYSTEM_LIBRARY})
endif()
