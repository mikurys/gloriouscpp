cmake_minimum_required (VERSION 2.6)
project (glor_system CXX)

include("../lib_options.cmake")

file(GLOB glor_system_sources # All files in directory:
	"*.h"
	"*.hpp"
	"*.cpp"
)

add_library (glor_system STATIC ${glor_system_sources})
if (CYGWIN OR APPLE)
        target_link_libraries (glor_system pthread ${Boost_SYSTEM_LIBRARY} )
elseif(MSVC)
        target_link_libraries (glor_system ${Boost_SYSTEM_LIBRARY})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DWIN32 /D_WINDOWS /W3 /GR /EHsc /MDd -DRELEASEMODE=1")
else()
        target_link_libraries (glor_system pthread ${Boost_SYSTEM_LIBRARY} rt)
endif()
set_target_properties (glor_system PROPERTIES OUTPUT_NAME "glor_system")

# target_link_libraries (upnpc-static ${LDLIBS}) # to add used libs
