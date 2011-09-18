############################## UTILITY FUNCTIONS ##############################

# Set the value of a variable
function(globalset VARIABLE VALUE)
    set(${VARIABLE} ${VALUE} CACHE INTERNAL "" FORCE)
endfunction()


########################## GENERIC PLUGINS FUNCTIONS ##########################

# Read a list of enabled or disabled plugin names from a file
function(plugins_read_list OUTPUT_VAR FILENAME ENABLED)
    set(LIST "")

    if (EXISTS "${FILENAME}")
        if (ENABLED)
            set(PATTERN "^\\+")
        else()
            set(PATTERN "^-")
        endif()

        file(STRINGS "${FILENAME}" PLUGINS_LIST REGEX "${PATTERN}")

        set(PATTERN "${PATTERN}[ ]*")

        foreach (PLUGIN ${PLUGINS_LIST})
            string(REGEX REPLACE "${PATTERN}" "" PLUGIN "${PLUGIN}")
            list(APPEND LIST "${PLUGIN}")
        endforeach()
    endif()

    globalset(${OUTPUT_VAR} "${LIST}")
endfunction()


# Write the list of enabled and disabled plugin names to a file
function(plugins_write_list PLUGIN_TYPE PLUGIN_TYPE_NAME FILENAME)
    set(FILE_CONTENT
"# This file contain the list of all the ${PLUGIN_TYPE_NAME} that were found by the MASH Framework.
#
# If you want to disable the compilation of one of them, put a '-' (minus) character in front of
# its name.
#
# If you want to enable the compilation of one of them, put a '+' (plus) character in front of
# its name.
#
# By default, everything is compiled.

")

    foreach (DETECTED_PLUGIN ${DETECTED_${PLUGIN_TYPE}})
        plugins_must_compile(${PLUGIN_TYPE} ${DETECTED_PLUGIN} TO_COMPILE)
        if (TO_COMPILE)
            set(FILE_CONTENT "${FILE_CONTENT}\n+ ${DETECTED_PLUGIN}")
        else()
            set(FILE_CONTENT "${FILE_CONTENT}\n- ${DETECTED_PLUGIN}")
        endif()
    endforeach()

    file(WRITE "${FILENAME}" "${FILE_CONTENT}")
endfunction()


# Display the list of plugins on the screen
function(plugins_display PLUGINS_TYPE LIBRARIES_TYPE LABEL)

    message(STATUS "\n--------------------------------------------------------------------------------")
    message(STATUS "${PLUGINS_TYPE}")

    if (LIBRARIES_TYPE)
        message(STATUS "")
        message(STATUS "  Libraries:")
        message(STATUS "")

        foreach(LIB ${DETECTED_${LIBRARIES_TYPE}})
            plugins_must_compile(${LIBRARIES_TYPE} ${LIB} TO_COMPILE)
            if (NOT TO_COMPILE)
                message(STATUS "    - ${LIB}")
            else()
                plugins_is_new(${LIBRARIES_TYPE} ${LIB} IS_NEW)
                if (IS_NEW)
                    message(STATUS "    + ${LIB} (new)")
                else()
                    message(STATUS "    + ${LIB}")
                endif()
            endif()
        endforeach()

        if (DETECTED_${LIBRARIES_TYPE} STREQUAL "")
            message(STATUS "    (NONE)")
        endif()

        message(STATUS "")
        message(STATUS "  ${LABEL}:")
    endif()

    message(STATUS "")

    foreach(PLUGIN ${DETECTED_${PLUGINS_TYPE}})
        plugins_must_compile(${PLUGINS_TYPE} ${PLUGIN} TO_COMPILE)
        if (NOT TO_COMPILE)
            message(STATUS "    - ${PLUGIN}")
        else()
            plugins_is_new(${PLUGINS_TYPE} ${PLUGIN} IS_NEW)
            if (IS_NEW)
                message(STATUS "    + ${PLUGIN} (new)")
            else()
                message(STATUS "    + ${PLUGIN}")
            endif()
        endif()
    endforeach()

    if (DETECTED_${PLUGINS_TYPE} STREQUAL "")
        message(STATUS "    (NONE)")
    endif()

    message(STATUS "")
    message(STATUS "--------------------------------------------------------------------------------")
    message(STATUS "")

endfunction()


# Indicate if a plugin must be compiled
function(plugins_must_compile PLUGIN_TYPE PLUGIN OUTPUT_VAR)
    set(PATTERN "^(${PLUGIN};)|(;${PLUGIN}$)|(^${PLUGIN}$)|(;${PLUGIN};)")
    string(REGEX MATCH "${PATTERN}" FOUND "${DISABLED_${PLUGIN_TYPE}}")

    if (FOUND)
        globalset(${OUTPUT_VAR} FALSE)
    else()
        globalset(${OUTPUT_VAR} TRUE)
    endif()
endfunction()


# Indicate if a plugin is new
function(plugins_is_new PLUGIN_TYPE PLUGIN OUTPUT_VAR)

    set(PATTERN "^(${PLUGIN};)|(;${PLUGIN}$)|(^${PLUGIN}$)|(;${PLUGIN};)")

    string(REGEX MATCH "${PATTERN}" FOUND "${ENABLED_${PLUGIN_TYPE}}")
    if (NOT FOUND)
        string(REGEX MATCH "${PATTERN}" FOUND "${DISABLED_${PLUGIN_TYPE}}")
    endif()

    if (FOUND)
        globalset(${OUTPUT_VAR} FALSE)
    else()
        globalset(${OUTPUT_VAR} TRUE)
    endif()
endfunction()


# Indicate if a plugin is an advanced or a simple one
function(plugins_is_advanced PLUGIN_TYPE PLUGIN LOCATIONS OUTPUT_VAR)

    # Iterate through all the plugin locations
    foreach (LOCATION ${LOCATIONS})
        if (EXISTS "${LOCATION}/${PLUGIN}")
            globalset(${OUTPUT_VAR} TRUE)
            break()
        endif()
    endforeach()

    globalset(${OUTPUT_VAR} FALSE)
endfunction()


# Detect all the available plugin
function(plugins_detect PLUGIN_TYPE LOCATIONS)

    set(DETECTED_PLUGINS "")

    # Iterate through all the plugin locations
    foreach (LOCATION ${LOCATIONS})
        set(FILTER_IGNORED "")

        file(GLOB_RECURSE IGNORE_FILES RELATIVE "${LOCATION}" "${LOCATION}/mashignore")
        foreach (IGNORE_FILE ${IGNORE_FILES})
            set(SPLIT_REGEX "^([A-Za-z0-9_]+)/mashignore$")
            string(REGEX REPLACE ${SPLIT_REGEX} "\\1" PREFIX_PATH ${IGNORE_FILE})

            file(STRINGS "${LOCATION}/${IGNORE_FILE}" IGNORE_LIST)
            foreach (IGNORED_PATH ${IGNORE_LIST})
                string(STRIP "${IGNORED_PATH}" IGNORED_PATH)
                if (IGNORED_PATH)
                    set(FILTER_IGNORED "${FILTER_IGNORED}|(^${PREFIX_PATH}/${IGNORED_PATH})")
                endif()
            endforeach()
        endforeach()

        file(GLOB_RECURSE PLUGINS_SRCS RELATIVE "${LOCATION}" "${LOCATION}/*.cpp" "${LOCATION}/*.cc")

        if (NOT IDE_USED)
            set(FILTER_REGEX "^(upload/)|(^libraries/)|(^template.cpp$)${FILTER_IGNORED}|(/\\._)|(~$)")
        else()
            set(FILTER_REGEX "^(upload/)|(^libraries/)|(^unittests/)|(^template.cpp$)${FILTER_IGNORED}|(/\\._)|(~$)")
        endif()

        set(PLUGINS_SRCS_FILTERED "")
        foreach (PLUGIN_SRC ${PLUGINS_SRCS})
            if (NOT PLUGIN_SRC MATCHES "${FILTER_REGEX}")
                list(APPEND PLUGINS_SRCS_FILTERED "${PLUGIN_SRC}")
            endif()
        endforeach()

        # Iterate through all the source files
        foreach (PLUGIN_SRC ${PLUGINS_SRCS_FILTERED})

            string(REPLACE ".cpp" "" PLUGIN "${PLUGIN_SRC}")
            string(REPLACE ".cc" "" PLUGIN "${PLUGIN}")
            string(REPLACE " " "_" PLUGIN "${PLUGIN}")

            # Retrieve the username and the plugin name
            set(SPLIT_REGEX1 "^([A-Za-z0-9_]+)/([A-Za-z0-9_]+)/([A-Za-z0-9_/]+)$")
            set(SPLIT_REGEX2 "^([A-Za-z0-9_]+)/([A-Za-z0-9_]+)$")
    
            if (PLUGIN MATCHES ${SPLIT_REGEX1})
                # Advanced plugin: username/plugin_name/filename
                string(REGEX REPLACE ${SPLIT_REGEX1} "\\1" PLUGIN_USERNAME ${PLUGIN})
                string(REGEX REPLACE ${SPLIT_REGEX1} "\\2" PLUGIN_NAME ${PLUGIN})

                list(APPEND DETECTED_PLUGINS "${PLUGIN_USERNAME}/${PLUGIN_NAME}")
            else()
                if (PLUGIN MATCHES ${SPLIT_REGEX2})
                    # Simple plugin: username/plugin_name
                    list(APPEND DETECTED_PLUGINS "${PLUGIN}")
                endif()
            endif()
            
        endforeach()

    endforeach()

    list(REMOVE_DUPLICATES DETECTED_PLUGINS)
    globalset(DETECTED_${PLUGIN_TYPE} "${DETECTED_PLUGINS}")

endfunction()


# Detect all the available plugin libraries
function(plugins_detect_libraries PLUGIN_TYPE LOCATIONS)

    set(DETECTED_LIBRARIES "")

    # Iterate through all the plugin locations
    foreach (LOCATION ${LOCATIONS})
        set(FILTER_IGNORED "")
        set(FIRST TRUE)

        if (EXISTS "${LOCATION}/libraries/mashignore")
            file(STRINGS "${LOCATION}/libraries/mashignore" IGNORE_LIST)
            foreach (IGNORED_PATH ${IGNORE_LIST})
                string(STRIP "${IGNORED_PATH}" IGNORED_PATH)
                if (IGNORED_PATH)
                    if (FIRST)
                        set(FILTER_IGNORED "^(${IGNORED_PATH})")
                        set(FIRST FALSE)
                    else()
                        set(FILTER_IGNORED "${FILTER_IGNORED}|(^${IGNORED_PATH})")
                    endif()
                endif()
            endforeach()
        endif()

        file(GLOB_RECURSE DETECTED_LIBRARIES_PATHS RELATIVE "${LOCATION}/libraries" "${LOCATION}/libraries/*/*.cpp" "${LOCATION}/libraries/*/*.cc" "${LOCATION}/libraries/*/*.c")

        foreach (DETECTED_LIBRARY_PATH ${DETECTED_LIBRARIES_PATHS})
            string(REPLACE "//" "/" RESULT "${DETECTED_LIBRARY_PATH}")

            # Allows the libraries to have a 'test' folder (we don't care about it)
            string(REGEX MATCH "^[^/]+" RESULT "${RESULT}")
            if (FILTER_IGNORED)
                if (NOT RESULT MATCHES "${FILTER_IGNORED}")
                    list(APPEND DETECTED_LIBRARIES "${RESULT}")
                endif()
            else()
                list(APPEND DETECTED_LIBRARIES "${RESULT}")
            endif()
        endforeach()
        
    endforeach()

    list(REMOVE_DUPLICATES DETECTED_LIBRARIES)
    globalset(DETECTED_${PLUGIN_TYPE} "${DETECTED_LIBRARIES}")

endfunction()


# Retrieves the source files of a plugin
function(plugins_get_source_files PLUGIN LOCATIONS OUTPUT_VAR)

    globalset(${OUTPUT_VAR} "")

    foreach(LOCATION ${LOCATIONS})
        
        # Is the plugin a library?
        if (EXISTS "${LOCATION}/libraries/${PLUGIN}")
            file(GLOB_RECURSE SRCS "${LOCATION}/libraries/${PLUGIN}/*.cpp" "${LOCATION}/libraries/${PLUGIN}/*.cc" "${LOCATION}/libraries/${PLUGIN}/*.c")

            set(FILTER_IGNORED "")
            set(FIRST TRUE)

            if (EXISTS "${LOCATION}/libraries/mashignore")
                file(STRINGS "${LOCATION}/libraries/mashignore" IGNORE_LIST)
                foreach (IGNORED_PATH ${IGNORE_LIST})
                    string(STRIP "${IGNORED_PATH}" IGNORED_PATH)
                    if (IGNORED_PATH)
                        if (FIRST)
                            set(FILTER_IGNORED "^(${LOCATION}/libraries/${IGNORED_PATH})")
                            set(FIRST FALSE)
                        else()
                            set(FILTER_IGNORED "${FILTER_IGNORED}|(^${LOCATION}/libraries/${IGNORED_PATH})")
                        endif()
                    endif()
                endforeach()
            endif()

            if (FILTER_IGNORED)
                set(SRCS_FILTERED "")
                foreach (CURRENT_SRC ${SRCS})
                    if (NOT CURRENT_SRC MATCHES "${FILTER_IGNORED}")
                        list(APPEND SRCS_FILTERED ${CURRENT_SRC})
                    endif()
                endforeach()

                globalset(${OUTPUT_VAR} "${SRCS_FILTERED}")
            else()
                globalset(${OUTPUT_VAR} "${SRCS}")
            endif()
            break()
        endif()
        
        # Retrieve the username
        set(SPLIT_REGEX "^([A-Za-z0-9_]+)/")
        string(REGEX REPLACE ${SPLIT_REGEX} "\\1" USERNAME ${PLUGIN})
        
        # Retrieve the files to ignore
        set(FILTER_IGNORED "")
        set(FIRST TRUE)

        if (EXISTS "${LOCATION}/${USERNAME}/mashignore")
            file(STRINGS "${LOCATION}/${USERNAME}/mashignore" IGNORE_LIST)
            foreach (IGNORED_PATH ${IGNORE_LIST})
                string(STRIP "${IGNORED_PATH}" IGNORED_PATH)
                if (IGNORED_PATH)
                    if (FIRST)
                        set(FILTER_IGNORED "^(${LOCATION}/${USERNAME}/${IGNORED_PATH})")
                        set(FIRST FALSE)
                    else()
                        set(FILTER_IGNORED "${FILTER_IGNORED}|(^${LOCATION}/${USERNAME}/${IGNORED_PATH})")
                    endif()
                endif()
            endforeach()
        endif()
        
        # Is the plugin an advanced one?
        if (IS_DIRECTORY "${LOCATION}/${PLUGIN}")
            file(GLOB_RECURSE SRCS "${LOCATION}/${PLUGIN}/*.cpp" "${LOCATION}/${PLUGIN}/*.cc")

            if (FILTER_IGNORED)
                set(SRCS_FILTERED "")
                foreach (CURRENT_SRC ${SRCS})
                    if (NOT CURRENT_SRC MATCHES "${FILTER_IGNORED}")
                        list(APPEND SRCS_FILTERED ${CURRENT_SRC})
                    endif()
                endforeach()

                globalset(${OUTPUT_VAR} "${SRCS_FILTERED}")
            else()
                globalset(${OUTPUT_VAR} "${SRCS}")
            endif()
            break()
        endif()

        # Is the plugin a simple one?
        if (EXISTS "${LOCATION}/${PLUGIN}.cpp")
            if (FILTER_IGNORED)
                if (NOT "${LOCATION}/${PLUGIN}.cpp" MATCHES "${FILTER_IGNORED}")
                    globalset(${OUTPUT_VAR} "${LOCATION}/${PLUGIN}.cpp")
                endif()
            else()
                globalset(${OUTPUT_VAR} "${LOCATION}/${PLUGIN}.cpp")
            endif()
            break()
        endif()

        if (EXISTS "${LOCATION}/${PLUGIN}.cc")
            if (FILTER_IGNORED)
                if (NOT "${LOCATION}/${PLUGIN}.cc" MATCHES "${FILTER_IGNORED}")
                    globalset(${OUTPUT_VAR} "${LOCATION}/${PLUGIN}.cc")
                endif()
            else()
                globalset(${OUTPUT_VAR} "${LOCATION}/${PLUGIN}.cc")
            endif()
            break()
        endif()
        
    endforeach()

endfunction()


# Create a target for each enabled plugin library
function(plugins_create_libraries_targets LIBRARIES_TYPE LOCATIONS LIBRARY_PREFIX)

    # Setup the search paths
    include_directories(${MASH_SOURCE_DIR})

    foreach(LOCATION ${LOCATIONS})
        include_directories(${LOCATION} ${LOCATION}/libraries)
    endforeach()


    set(LIBRARIES_TARGETS "")

    foreach(LIB ${DETECTED_${LIBRARIES_TYPE}})
        plugins_must_compile(${LIBRARIES_TYPE} ${LIB} TO_COMPILE)
        if (TO_COMPILE)

            set(TARGET_NAME "${LIBRARY_PREFIX}-${LIB}")
            string(REPLACE "/" "-" TARGET_NAME "${TARGET_NAME}")

            # Retrieve the source files
            plugins_get_source_files(${LIB} "${LOCATIONS}" "SOURCE_FILES")

            # Create the target
            add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})
    
            set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_FLAGS "-fPIC"
                                                            INSTALL_RPATH "."
                                                            BUILD_WITH_INSTALL_RPATH ON)

            list(APPEND LIBRARIES_TARGETS "${TARGET_NAME}")
        endif()
    endforeach()

    globalset(TARGETS_${LIBRARIES_TYPE} "${LIBRARIES_TARGETS}")

endfunction()


# Create a target for each enabled plugin
function(plugins_create_targets PLUGINS_TYPE LOCATIONS TARGET_PREFIX TARGETS_TO_LINK LINK_FLAGS DEST_FOLDER)

    # Setup the search paths
    include_directories(${MASH_SOURCE_DIR})

    foreach(LOCATION ${LOCATIONS})
        include_directories(${LOCATION} ${LOCATION}/libraries)
    endforeach()

    foreach(PLUGIN ${DETECTED_${PLUGINS_TYPE}})
        plugins_must_compile(${PLUGINS_TYPE} ${PLUGIN} TO_COMPILE)
        if (TO_COMPILE)

            set(TARGET_NAME "${TARGET_PREFIX}-${PLUGIN}")
            string(REPLACE "/" "-" TARGET_NAME "${TARGET_NAME}")

            # Retrieve the source files
            plugins_get_source_files(${PLUGIN} "${LOCATIONS}" "SOURCE_FILES")

            # Create the target
            add_library(${TARGET_NAME} MODULE ${SOURCE_FILES})

            target_link_libraries(${TARGET_NAME} mash-core mash-utils ${TARGETS_TO_LINK})

            set(SPLIT_REGEX "^([A-Za-z0-9_]+)/([A-Za-z0-9_]+)$")
            string(REGEX REPLACE ${SPLIT_REGEX} "\\1" PLUGIN_USERNAME ${PLUGIN})
            string(REGEX REPLACE ${SPLIT_REGEX} "\\2" PLUGIN_NAME ${PLUGIN})

            get_target_property(OUTPUT_DIRECTORY ${TARGET_NAME} LIBRARY_OUTPUT_DIRECTORY)

            set_target_properties(${TARGET_NAME}
                                  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/${DEST_FOLDER}/${PLUGIN_USERNAME}"
                                             OUTPUT_NAME "${PLUGIN_NAME}"
                                             LINK_FLAGS "${LINK_FLAGS}"
                                             INSTALL_RPATH "."
                                             BUILD_WITH_INSTALL_RPATH ON
                                             COMPILE_FLAGS "-fPIC")

            # Make the 'classifiers' target depend on this one
            add_dependencies(${DEST_FOLDER} ${TARGET_NAME})

            # Installation stuff - Experiments Server
            install(TARGETS ${TARGET_NAME}
                    LIBRARY DESTINATION experiment-server/${DEST_FOLDER}/${PLUGIN_USERNAME}
                    CONFIGURATIONS Release
                    COMPONENT "experiment-server"
                   )

        endif()
    endforeach()

endfunction()


######################## CLASSIFIER-RELATED FUNCTIONS #########################

function(classifiers_read_list)
    plugins_read_list(ENABLED_CLASSIFIERS "${MASH_BINARY_DIR}/classifiers.txt" TRUE)
    plugins_read_list(DISABLED_CLASSIFIERS "${MASH_BINARY_DIR}/classifiers.txt" FALSE)
    plugins_read_list(ENABLED_CLASSIFICATION_LIBRARIES "${MASH_BINARY_DIR}/classification_libraries.txt" TRUE)
    plugins_read_list(DISABLED_CLASSIFICATION_LIBRARIES "${MASH_BINARY_DIR}/classification_libraries.txt" FALSE)
endfunction()


function(classifiers_write_list)
    plugins_write_list(CLASSIFIERS "classifiers" "${MASH_BINARY_DIR}/classifiers.txt")
    plugins_write_list(CLASSIFICATION_LIBRARIES "classification libraries" "${MASH_BINARY_DIR}/classification_libraries.txt")
endfunction()


function(classifiers_detect)
    plugins_detect(CLASSIFIERS "${MASH_CLASSIFIER_LOCATIONS}")
    plugins_detect_libraries(CLASSIFICATION_LIBRARIES "${MASH_CLASSIFIER_LOCATIONS}")
endfunction()


function(classifiers_display)
    plugins_display(CLASSIFIERS CLASSIFICATION_LIBRARIES "Classifiers")
endfunction()


function(classifiers_create_targets)
    # Create a group target for all the classifiers (so any other target that depends on the
    # classifiers one can use it instead)
    add_custom_target(classifiers ALL COMMENT "Building the classifiers")

    plugins_create_libraries_targets(CLASSIFICATION_LIBRARIES "${MASH_CLASSIFIER_LOCATIONS}" "classification-library")
    plugins_create_targets(CLASSIFIERS "${MASH_CLASSIFIER_LOCATIONS}" "classifier" "mash-classification;mash-instrumentation;${TARGETS_CLASSIFICATION_LIBRARIES}" "" "classifiers")
endfunction()


####################### GOALPLANNERS-RELATED FUNCTIONS ########################

function(goalplanners_read_list)
    plugins_read_list(ENABLED_GOALPLANNERS "${MASH_BINARY_DIR}/goalplanners.txt" TRUE)
    plugins_read_list(DISABLED_GOALPLANNERS "${MASH_BINARY_DIR}/goalplanners.txt" FALSE)
    plugins_read_list(ENABLED_GOALPLANNING_LIBRARIES "${MASH_BINARY_DIR}/goalplanning_libraries.txt" TRUE)
    plugins_read_list(DISABLED_GOALPLANNING_LIBRARIES "${MASH_BINARY_DIR}/goalplanning_libraries.txt" FALSE)
endfunction()


function(goalplanners_write_list)
    plugins_write_list(GOALPLANNERS "goal-planners" "${MASH_BINARY_DIR}/goalplanners.txt")
    plugins_write_list(GOALPLANNING_LIBRARIES "goal-planning libraries" "${MASH_BINARY_DIR}/goalplanning_libraries.txt")
endfunction()


function(goalplanners_detect)
    plugins_detect(GOALPLANNERS "${MASH_GOALPLANNER_LOCATIONS}")
    plugins_detect_libraries(GOALPLANNING_LIBRARIES "${MASH_GOALPLANNER_LOCATIONS}")
endfunction()


function(goalplanners_display)
    plugins_display(GOALPLANNERS GOALPLANNING_LIBRARIES "Goal-planners")
endfunction()


function(goalplanners_create_targets)
    # Create a group target for all the goal-planners (so any other target that depends on the
    # goal-planners one can use it instead)
    add_custom_target(goalplanners ALL COMMENT "Building the goal-planners")

    plugins_create_libraries_targets(GOALPLANNING_LIBRARIES "${MASH_GOALPLANNER_LOCATIONS}" "goalplanning-library")
    plugins_create_targets(GOALPLANNERS "${MASH_GOALPLANNER_LOCATIONS}" "goalplanner" "mash-goalplanning;mash-instrumentation;${TARGETS_GOALPLANNING_LIBRARIES}" "" "goalplanners")
endfunction()


####################### INSTRUMENTS-RELATED FUNCTIONS #########################

function(instruments_read_list)
    plugins_read_list(ENABLED_INSTRUMENTS "${MASH_BINARY_DIR}/instruments.txt" TRUE)
    plugins_read_list(DISABLED_INSTRUMENTS "${MASH_BINARY_DIR}/instruments.txt" FALSE)
    plugins_read_list(ENABLED_INSTRUMENTATION_LIBRARIES "${MASH_BINARY_DIR}/instrumentation_libraries.txt" TRUE)
    plugins_read_list(DISABLED_INSTRUMENTATION_LIBRARIES "${MASH_BINARY_DIR}/instrumentation_libraries.txt" FALSE)
endfunction()


function(instruments_write_list)
    plugins_write_list(INSTRUMENTS "instruments" "${MASH_BINARY_DIR}/instruments.txt")
    plugins_write_list(INSTRUMENTATION_LIBRARIES "instrumentation libraries" "${MASH_BINARY_DIR}/instrumentation_libraries.txt")
endfunction()


function(instruments_detect)
    plugins_detect(INSTRUMENTS "${MASH_INSTRUMENT_LOCATIONS}")
    plugins_detect_libraries(INSTRUMENTATION_LIBRARIES "${MASH_INSTRUMENT_LOCATIONS}")
endfunction()


function(instruments_display)
    plugins_display(INSTRUMENTS INSTRUMENTATION_LIBRARIES "Instruments")
endfunction()


function(instruments_create_targets)
    # Create a group target for all the instruments (so any other target that depends on the
    # instruments one can use it instead)
    add_custom_target(instruments ALL COMMENT "Building the instruments")

    plugins_create_libraries_targets(INSTRUMENTATION_LIBRARIES "${MASH_INSTRUMENT_LOCATIONS}" "instrumentation-library")
    plugins_create_targets(INSTRUMENTS "${MASH_INSTRUMENT_LOCATIONS}" "instrument" "mash-instrumentation;${TARGETS_INSTRUMENTATION_LIBRARIES}" "" "instruments")
endfunction()


######################## HEURISTICS-RELATED FUNCTIONS #########################

function(heuristics_read_list)
    plugins_read_list(ENABLED_HEURISTICS "${MASH_BINARY_DIR}/heuristics.txt" TRUE)
    plugins_read_list(DISABLED_HEURISTICS "${MASH_BINARY_DIR}/heuristics.txt" FALSE)
endfunction()


function(heuristics_write_list)
    plugins_write_list(HEURISTICS "heuristics" "${MASH_BINARY_DIR}/heuristics.txt")
endfunction()


function(heuristics_detect)
    plugins_detect(HEURISTICS "${MASH_HEURISTIC_LOCATIONS}")
endfunction()


function(heuristics_display)
    plugins_display(HEURISTICS "" "Heuristics")
endfunction()


function(heuristics_create_targets)
    # Create a group target for all the heuristics (so any other target that depends on the
    # heuristics one can use it instead)
    add_custom_target(heuristics ALL COMMENT "Building the heuristics")

    set(LINK_FLAGS "")
    if (WIN32 AND IDE_USED)
        set(LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}\"${MASH_SOURCE_DIR}/heuristics/heuristic.def\"")
    endif()

    plugins_create_targets(HEURISTICS "${MASH_HEURISTIC_LOCATIONS}" "heuristic" "" "${LINK_FLAGS}" "heuristics")
endfunction()
