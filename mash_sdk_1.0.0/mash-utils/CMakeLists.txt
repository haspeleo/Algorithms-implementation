# Setup the search paths
include_directories(${MASH_SOURCE_DIR})

# List the source files of mash-utils
set(SRCS errors.cpp
         stringutils.cpp
)

if (NOT MASH_SDK)
    list(APPEND SRCS arguments_list.cpp
                     outstream.cpp
                     data_reader.cpp
                     data_writer.cpp
                     random_number_generator.cpp
    )
endif()

add_library(mash-utils SHARED ${SRCS})


if (NOT WIN32)
    target_link_libraries(mash-utils dl)
    set_target_properties(mash-utils PROPERTIES COMPILE_FLAGS "-fPIC")
else()
	set_target_properties(mash-utils PROPERTIES COMPILE_DEFINITIONS "MASH_EXPORTS")
	set_target_properties(mash-utils PROPERTIES COMPILE_FLAGS "/wd4251")
endif()

set_target_properties(mash-utils PROPERTIES INSTALL_RPATH ".")
set_target_properties(mash-utils PROPERTIES BUILD_WITH_INSTALL_RPATH ON)


if (NOT MASH_SDK AND NOT WIN32)
    # Installation stuff - Compilation Server
    install(TARGETS mash-utils
            LIBRARY DESTINATION compilation-server
    		CONFIGURATIONS Release
            COMPONENT "compilation-server"
           )

    install(FILES declarations.h platform.h
            DESTINATION compilation-server/mash-utils
            CONFIGURATIONS Release
            COMPONENT "compilation-server"
           )


    # Installation stuff - Experiments Server
    install(TARGETS mash-utils
            LIBRARY DESTINATION experiment-server
    		CONFIGURATIONS Release
            COMPONENT "experiment-server"
           )

    install(FILES declarations.h platform.h
            DESTINATION experiment-server/mash-utils
            CONFIGURATIONS Release
            COMPONENT "experiment-server"
           )
endif()
