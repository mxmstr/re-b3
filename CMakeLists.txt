cmake_minimum_required(VERSION 3.10)

project(Burnout3Reimplementation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add more project configurations here as needed

# List of source files
set(SOURCES
    src/GtIntersection.cpp
    # Add other .cpp files here if the project grows
)

# Example of how to use the SOURCES variable if an executable is defined:
# add_executable(Burnout3Reimplementation ${SOURCES})
