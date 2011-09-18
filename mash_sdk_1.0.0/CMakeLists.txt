cmake_minimum_required(VERSION 2.6)
project(MASH)


# Options
set(MASH_HEURISTIC_LOCATIONS "${MASH_SOURCE_DIR}/heuristics;${MASH_SOURCE_DIR}/../heuristics" CACHE STRING "Locations of the heuristics, separated by ;")


# Select a default build configuration if none was choosen
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()


# Indicates that this is the SDK
set(MASH_SDK true)


# Indicates if we are generating a project for one of the supported IDEs
if (CMAKE_GENERATOR MATCHES "(^Xcode$)|(^Visual Studio)")
	set(IDE_USED true)
else()
	set(IDE_USED false)
endif()



# Use relative paths, mostly to reduce path size for command-line limits on windows
if (WIN32)
    # This seems to break Xcode projects so definitely don't enable on Apple builds
    set(CMAKE_USE_RELATIVE_PATHS true)
    set(CMAKE_SUPPRESS_REGENERATION true)
endif()


# Set the output paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${MASH_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${MASH_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${MASH_BINARY_DIR}/bin")


# Set the global compiler definitions
set_directory_properties(PROPERTIES COMPILE_DEFINITIONS_RELEASE "NDEBUG")

set(GLOBAL_DEFINITIONS "")

list(APPEND GLOBAL_DEFINITIONS 	"MASH_DATA_DIR=\"${MASH_SOURCE_DIR}/data/\""
							   	"MASH_HEURISTICS_DIR=\"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heuristics\"")

if (IDE_USED)
	list(APPEND GLOBAL_DEFINITIONS "MASH_IDE_USED")
endif()

list(APPEND GLOBAL_DEFINITIONS "MASH_SDK")

set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "${GLOBAL_DEFINITIONS}")


# Import our custom functions
include("${MASH_SOURCE_DIR}/cmake/plugins.cmake")


# Subdirectories to process
add_subdirectory(dependencies)
add_subdirectory(mash)
add_subdirectory(mash-utils)
add_subdirectory(sdk)
add_subdirectory(heuristics)
