# Setup the search paths
include_directories(${MASH_SOURCE_DIR}
                    ${MASH_SOURCE_DIR}/dependencies
                    ${MASH_SOURCE_DIR}/dependencies/include
                    ${MASH_SOURCE_DIR}/dependencies/FreeImage)

# Create and link the executable
add_executable(testheuristic testheuristic.cpp)
add_dependencies(testheuristic freeimage heuristics)

target_link_libraries(testheuristic mash-core freeimage)

set_target_properties(testheuristic PROPERTIES COMPILE_DEFINITIONS "FREEIMAGE_LIB"
                                               INSTALL_RPATH "."
                                               BUILD_WITH_INSTALL_RPATH ON)

if (NOT WIN32)
    set_target_properties(testheuristic PROPERTIES COMPILE_FLAGS "-fPIC")
endif()
