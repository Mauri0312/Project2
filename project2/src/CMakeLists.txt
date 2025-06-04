add_library(developer STATIC
    developer.cpp
)
# Create a static library named 'developer' from developer.cpp

target_include_directories(developer PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)
# Make the src directory available for #include to all targets linking to this library
