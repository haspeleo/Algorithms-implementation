# Setup the search paths
include_directories(${MASH_SOURCE_DIR}
                    ${MASH_SOURCE_DIR}/dependencies
                    ${MASH_SOURCE_DIR}/dependencies/include
                    ${MASH_SOURCE_DIR}/dependencies/FreeImage)

# List the source files of mash-core
set(SRCS dynlibs_manager.cpp
         heuristics_manager.cpp
         image.cpp
         imageutils.cpp
)

if (NOT MASH_SDK)
    list(APPEND SRCS features_computer.cpp
                     images_cache.cpp
                     notifier.cpp
                     predictor_model.cpp
                     sandbox_notifier_proxy.cpp
                     sandboxed_heuristics_set.cpp
                     trusted_heuristics_set.cpp
    )
endif()

# Create the library
add_library(mash-core SHARED ${SRCS})
add_dependencies(mash-core mash-utils freeimage)
target_link_libraries(mash-core mash-utils freeimage)

if (NOT WIN32)
    target_link_libraries(mash-core dl)

    set_target_properties(mash-core PROPERTIES COMPILE_FLAGS "-fPIC")

    if (MASH_SDK)
        set_target_properties(mash-core PROPERTIES COMPILE_DEFINITIONS "FREEIMAGE_LIB")
    else()
        add_dependencies(mash-core mash-sandboxing)
        target_link_libraries(mash-core mash-sandboxing)
        set_target_properties(mash-core PROPERTIES COMPILE_DEFINITIONS "FREEIMAGE_LIB")
    endif()

else()
	set_target_properties(mash-core PROPERTIES COMPILE_DEFINITIONS "MASH_EXPORTS;FREEIMAGE_LIB")
	set_target_properties(mash-core PROPERTIES COMPILE_FLAGS "/wd4251")
endif()

set_target_properties(mash-core PROPERTIES INSTALL_RPATH ".")
set_target_properties(mash-core PROPERTIES BUILD_WITH_INSTALL_RPATH ON)


if (NOT MASH_SDK AND NOT WIN32)
    # Installation stuff - Compilation Server
    install(TARGETS mash-core
            LIBRARY DESTINATION compilation-server
    		CONFIGURATIONS Release
            COMPONENT "compilation-server"
           )

    install(FILES heuristic.h image.h
            DESTINATION compilation-server/mash
            CONFIGURATIONS Release
            COMPONENT "compilation-server"
           )


    # Installation stuff - Experiments Server
    install(TARGETS mash-core
            LIBRARY DESTINATION experiment-server
    		CONFIGURATIONS Release
            COMPONENT "experiment-server"
           )

    install(FILES heuristic.h image.h
            DESTINATION experiment-server/mash
            CONFIGURATIONS Release
            COMPONENT "experiment-server"
           )
endif()
