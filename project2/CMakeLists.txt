cmake_minimum_required(VERSION 3.20) # Require at least CMake version 3.20
project(SoftwareDevelopmentII LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Enforce the C++ standard

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic") # Enable common compiler warnings for better code quality

add_subdirectory(src)   # Add the source directory (library)
add_subdirectory(app)   # Add the application directory (main executable)
add_subdirectory(tests) # Add the tests directory (unit tests)

# Define a compiler definition for the resource path
# This assumes resources are relative to the project root.
# Adjust if resources are placed elsewhere.
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
target_compile_definitions(developer PUBLIC "RESOURCE_PATH=\"${RESOURCES_DIR}\"")
# This makes the RESOURCE_PATH macro available in the developer library and anything linking to it.

# Ensure the project can be configured and built without errors or warnings
# (No additional commands here, but this is a reminder for future maintainers.)
