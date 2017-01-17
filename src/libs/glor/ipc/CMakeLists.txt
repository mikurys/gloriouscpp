cmake_minimum_required (VERSION 2.6)
project (glor_ipc CXX)

include("../lib_options.cmake")

file(GLOB glor_ipc_sources # All files in directory:
	"*.h"
	"*.hpp"
	"*.cpp"
)

add_library (glor_ipc STATIC ${glor_ipc_sources})
add_dependencies (glor_ipc
	${Boost_SYSTEM_LIBRARY})
if (CYGWIN OR APPLE OR MSVC)
	target_link_libraries (glor_ipc
		glor_system)
else()
	target_link_libraries (glor_ipc
		glor_system
		rt)
endif()

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DWIN32 /D_WINDOWS /W3 /GR /EHsc /MDd -DRELEASEMODE=1")
endif()

set_target_properties (glor_ipc PROPERTIES OUTPUT_NAME "glor_ipc")

# target_link_libraries (upnpc-static ${LDLIBS}) # to add used libs
