add_executable(main main.cpp) # Create the main executable from main.cpp

# Link the developer library to the main executable.
# This ensures that the main application can use symbols from the developer library.
target_link_libraries(main developer) # The main application must link against this library.

# Ensure that the main application and tests can be executed without errors.
# (You may want to add dependencies or custom commands here if needed for your build/test setup.)
