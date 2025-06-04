#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// The RESOURCE_PATH macro is only intended for the main application, not for internal method logic.
// It is set by CMake and only compiled for the main application.

class Developer
{
   public:
    // Constructor initializes name and alias
    Developer(const std::string& name, const std::string& alias);

    // Getters for name, alias, and logo
    std::string getName() const;
    std::string getAlias() const;
    std::string getLogo() const;

    // Static method for simulating coffee drinking (can be called without an instance)
    static void drink_coffee();

    // Method to load the logo from a file; expects the FULL path to the file
    void load_logo_from_file(const std::string& full_filename_path);

    // Pure virtual method: must be implemented by derived classes
    virtual void solve_problem() = 0;
    virtual ~Developer() = default; // Virtual destructor for proper cleanup

   protected:
    // Protected members accessible by derived classes
    std::string name_;
    std::string alias_;
    std::string logo_;
};

// Overload the stream operator to print Developer information
std::ostream& operator<<(std::ostream& os, const Developer& dev);

class JuniorDeveloper : public Developer
{
   public:
    // Constructor passes parameters to base class
    JuniorDeveloper(const std::string& name, const std::string& alias);
    // Implementation of the pure virtual method
    void solve_problem() override;
};

class SeniorDeveloper : public Developer
{
   public:
    // Constructor passes parameters to base class
    SeniorDeveloper(const std::string& name, const std::string& alias);
    // Implementation of the pure virtual method
    void solve_problem() override;
};

#endif  // DEVELOPER_HPP
