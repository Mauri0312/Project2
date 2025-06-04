#include "developer.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>  // Include for std::stringstream

#include "gtest/gtest.h"

// Fixture for Developer tests
class DeveloperTest : public ::testing::Test
{
   protected:
    // We create a temporary path for the test logos
    std::string test_resource_path;

    void SetUp() override
    {
        // Create a unique temporary path for test resources
        // This prevents conflicts and accidental deletion of real resources
        test_resource_path = std::filesystem::temp_directory_path() / "test_resources_dev";
        std::filesystem::create_directories(test_resource_path);

        // Create dummy logo files for tests in this temporary path
        std::ofstream juniorLogoFile(test_resource_path + "/junior_logo_test.txt");
        juniorLogoFile << "Junior Test Logo";
        juniorLogoFile.close();

        std::ofstream seniorLogoFile(test_resource_path + "/senior_logo_test.txt");
        seniorLogoFile << "Senior Test Logo";
        seniorLogoFile.close();
    }

    void TearDown() override
    {
        // Clean up the temporary dummy logo files and the folder
        if (std::filesystem::exists(test_resource_path))
        {
            std::filesystem::remove_all(test_resource_path);
        }
    }
};

// Test for Developer constructor and getters
TEST_F(DeveloperTest, ConstructorAndGetters)
{
    JuniorDeveloper junior("John Doe", "JDev");
    EXPECT_EQ(junior.getName(), "John Doe");
    EXPECT_EQ(junior.getAlias(), "JDev");
    EXPECT_TRUE(junior.getLogo().empty());

    SeniorDeveloper senior("Jane Smith", "SDev");
    EXPECT_EQ(senior.getName(), "Jane Smith");
    EXPECT_EQ(senior.getAlias(), "SDev");
    EXPECT_TRUE(senior.getLogo().empty());
}

// Test for load_logo_from_file method
// This test must use the temporary path to avoid interfering with real resources
TEST_F(DeveloperTest, LoadLogoFromFile)
{
    JuniorDeveloper junior("John Doe", "JDev");
    // Call load_logo_from_file with the temporary path
    junior.load_logo_from_file(test_resource_path + "/junior_logo_test.txt");
    EXPECT_EQ(junior.getLogo(), "Junior Test Logo\n");

    SeniorDeveloper senior("Jane Smith", "SDev");
    // Call load_logo_from_file with the temporary path
    senior.load_logo_from_file(test_resource_path + "/senior_logo_test.txt");
    EXPECT_EQ(senior.getLogo(), "Senior Test Logo\n");
}

// Test for load_logo_from_file with invalid filename
TEST_F(DeveloperTest, LoadLogoFromFileInvalidFilename)
{
    JuniorDeveloper junior("John Doe", "JDev");
    // This test is still valid because the file really does not exist
    EXPECT_THROW(junior.load_logo_from_file("non_existent_file.txt"), std::runtime_error);
}

// Test for stream operator overload (<<)
TEST_F(DeveloperTest, StreamOperatorOutput)
{
    JuniorDeveloper junior("John Doe", "JDev");
    // Load logo from file using the temporary path
    junior.load_logo_from_file(test_resource_path + "/junior_logo_test.txt");

    std::stringstream ss;
    ss << junior;
    std::string expected_output = "Junior Test Logo\nName: John Doe\nAlias: JDev\n";
    EXPECT_EQ(ss.str(), expected_output);

    SeniorDeveloper senior("Jane Smith", "SDev");
    // Load logo from file using the temporary path
    senior.load_logo_from_file(test_resource_path + "/senior_logo_test.txt");

    std::stringstream ss_senior;
    ss_senior << senior;
    std::string expected_output_senior = "Senior Test Logo\nName: Jane Smith\nAlias: SDev\n";
    EXPECT_EQ(ss_senior.str(), expected_output_senior);
}
