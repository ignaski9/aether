cmake_minimum_required(VERSION 3.16)
project(aether LANGUAGES CXX)

# Enable C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debug/release rules (like xmake's add_rules)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Create the target
add_executable(
    aether
    src/main.cpp
    # You can glob files like in xmake, but it's discouraged:
    # file(GLOB SRC_FILES src/*.cpp)
    # add_executable(aether ${SRC_FILES})
)

# Include directories
target_include_directories(
    aether PRIVATE
    ${CMAKE_SOURCE_DIR}/dir/include
    ${CMAKE_SOURCE_DIR}/src/engine
    ${CMAKE_SOURCE_DIR}/src/head
)

# Link directories
link_directories(${CMAKE_SOURCE_DIR}/dir/lib)

# Link SFML libraries
target_link_libraries(aether PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

