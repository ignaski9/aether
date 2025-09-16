cmake_minimum_required(VERSION 3.22)
project(aether LANGUAGES CXX)

# Enable C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Create the target
add_executable(
    aether
    src/main.cpp
)


#find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
#target_link_libraries(aether PRIVATE sfml-graphics sfml-window sfml-system)


# Include directories
target_include_directories(
    aether PRIVATE
    ${CMAKE_SOURCE_DIR}/dir/include
    ${CMAKE_SOURCE_DIR}/src/engine
    ${CMAKE_SOURCE_DIR}/src/head
)

# Link directories
#link_directories(${CMAKE_SOURCE_DIR}/dir/lib)

# Link SFML libraries
#target_link_libraries(aether PRIVATE
 #   sfml-graphics
  #  sfml-window
   # sfml-system
#)


find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)  # Use capitalized component names. :contentReference[oaicite:6]{index=6}

target_link_libraries(aether PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

