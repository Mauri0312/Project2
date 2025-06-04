find_package(GTest CONFIG REQUIRED) # Find the GoogleTest package (required for unit testing)
add_executable(developer_test developer_test.cpp) # Create the test executable from the test source file
target_link_libraries(developer_test developer GTest::gtest_main) # Link the developer library and GoogleTest main to the test executable
