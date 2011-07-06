set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called cpp_simple_SOURCES containing all .cpp files:
set(cpp_simple_SOURCES cpp_simple.C midpoint.C f.C)

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

# Create an executable file called cpp_simple from sources:
add_executable(cpp_simple ${cpp_simple_SOURCES})
