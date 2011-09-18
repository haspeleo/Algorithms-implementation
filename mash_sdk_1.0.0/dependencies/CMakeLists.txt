if (NOT MASH_SDK AND NOT IDE_USED)
	add_subdirectory(UnitTest++)
	add_subdirectory(tinyxml)
endif()

add_subdirectory(FreeImage)
