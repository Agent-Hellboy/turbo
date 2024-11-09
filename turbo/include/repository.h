#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "package.h"
#include <unordered_map>
#include <memory>

class Repository {
public:
    std::unordered_map<std::string, std::shared_ptr<Package>> packages;

    void addPackage(const Package& pkg);
    std::shared_ptr<Package> getPackage(const std::string& name);
};

#endif
