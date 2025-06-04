#include "developer.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

// Developer class implementation
Developer::Developer(const std::string& name, const std::string& alias) : name_(name), alias_(alias), logo_("")
{
}

std::string Developer::getName() const
{
    return name_;
}

std::string Developer::getAlias() const
{
    return alias_;
}

std::string Developer::getLogo() const
{
    return logo_;
}

void Developer::drink_coffee()
{
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

// The method load_logo_from_file expects the FULL path to the file
void Developer::load_logo_from_file(const std::string& full_filename_path)
{
    // Check if the file exists before trying to open it
    if (!std::filesystem::exists(full_filename_path))
    {
        throw std::runtime_error("Invalid filename: " + full_filename_path);
    }

    std::ifstream file(full_filename_path);
    if (file.is_open())
    {
        std::string line;
        logo_ = "";  // Clear existing logo before loading new content
        // Read the file line by line and append to logo_
        while (std::getline(file, line))
        {
            logo_ += line + "\n";
        }
        file.close();
    }
    else
    {
        // Throw an exception if the file cannot be opened
        throw std::runtime_error("Could not open file: " + full_filename_path);
    }
}

// Overload the stream operator to print Developer information
std::ostream& operator<<(std::ostream& os, const Developer& dev)
{
    // If a logo exists, print it first
    if (!dev.getLogo().empty())
    {
        os << dev.getLogo();
    }
    os << "Name: " << dev.getName() << std::endl;
    os << "Alias: " << dev.getAlias() << std::endl;
    return os;
}

// JuniorDeveloper class implementation
JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& alias) : Developer(name, alias)
{
}

void JuniorDeveloper::solve_problem()
{
    std::cout << "Solving a problem:" << std::endl;
    // Print developer info using overloaded operator<<
    std::cout << *this;
    std::cout << "Puh, that was tough" << std::endl;
    // Simulate drinking coffee after solving the problem
    drink_coffee();
}

// SeniorDeveloper class implementation
SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& alias) : Developer(name, alias)
{
}

void SeniorDeveloper::solve_problem()
{
    std::cout << "Solving a problem:" << std::endl;
    // Print developer info using overloaded operator<<
    std::cout << *this;
    std::cout << "Ha, that was EZ!" << std::endl;
    // Simulate drinking coffee after solving the problem
    drink_coffee();
}
