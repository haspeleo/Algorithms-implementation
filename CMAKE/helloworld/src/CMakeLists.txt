set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(helloworld_SOURCES helloworld.cpp main.cpp)

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

# Create an executable file called helloworld from sources:
add_executable(helloworld ${helloworld_SOURCES})
