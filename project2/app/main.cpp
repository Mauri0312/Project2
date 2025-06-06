#include <iostream>
#include <memory>
#include <vector>

#include "developer.hpp"

// The RESOURCE_PATH macro is set by CMake and can be used here.
// If not defined, fallback to an empty string (should be defined by CMake).
#ifndef RESOURCE_PATH
#define RESOURCE_PATH ""
#endif

int main()
{
    // Create a vector to store shared pointers to Developer objects.
    // Using shared_ptr allows polymorphic storage and automatic memory management.
    std::vector<std::shared_ptr<Developer>> developers;

    // Create a SeniorDeveloper instance with name and alias.
    // Use make_shared for efficient memory allocation.
    auto seniorDev = std::make_shared<SeniorDeveloper>("Tony Stark", "Iron Man");
    // Load the logo for the senior developer from a file.
    // The file path is constructed using the RESOURCE_PATH macro.
    seniorDev->load_logo_from_file(std::string(RESOURCE_PATH) + "/senior_logo.txt");

    // Create a JuniorDeveloper instance with name and alias.
    auto juniorDev = std::make_shared<JuniorDeveloper>("Steve Rogers", "Captain America");
    // Load the logo for the junior developer from a file.
    juniorDev->load_logo_from_file(std::string(RESOURCE_PATH) + "/junior_logo.txt");

    // Add both developer instances to the vector.
    // This allows iteration and polymorphic behavior.
    developers.push_back(seniorDev);
    developers.push_back(juniorDev);

    // Iterate over all developers and let them solve a problem.
    // The solve_problem method is likely virtual and overridden in derived classes.
    for (const auto& dev : developers)
    {
        dev->solve_problem();
        // Print a newline for better output formatting.
        std::cout << std::endl;
    }

    return 0;
}
