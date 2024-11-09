#ifndef PACKAGE_MANAGER_H
#define PACKAGE_MANAGER_H

#include "repository.h"
#include <string>

class PackageManager {
private:
    Repository repository;

public:
    PackageManager(const Repository& repo);
    PackageManager(const std::string& yamlFile);  // Add this constructor
    bool install(const std::string& packageName);
};

#endif
