#include "repository.h"

void Repository::addPackage(const Package& pkg) {
    packages[pkg.name] = std::make_shared<Package>(pkg);
}

std::shared_ptr<Package> Repository::getPackage(const std::string& name) {
    return packages.find(name) != packages.end() ? packages[name] : nullptr;
}
