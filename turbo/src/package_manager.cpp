#include <iostream>
#include "package_manager.h"
#include "yaml_parser.h"
#include "utils.h"

PackageManager::PackageManager(const Repository& repo) : repository(repo) {}

// New constructor that takes a YAML file path
PackageManager::PackageManager(const std::string& yamlFile) {
    auto packages = parsePackagesFromYAML(yamlFile);  // Load packages from YAML
    for (const auto& pkg : packages) {
        repository.addPackage(pkg);
    }
}


bool PackageManager::install(const std::string& packageName) {
    auto pkg = repository.getPackage(packageName);
    if (!pkg) {
        std::cerr << "Package " << packageName << " not found.\n";
        return false;
    }

    std::cout << "Installing " << pkg->name << " version " << pkg->version << "\n";

    for (const auto& dep : pkg->dependencies) {
        if (!install(dep)) {
            std::cerr << "Failed to install dependency: " << dep << "\n";
            return false;
        }
    }

    std::string downloadPath = "./" + pkg->name + "-" + pkg->version + ".zip";
    if (downloadPackage(pkg->source, downloadPath)) {
        std::cout << "Successfully downloaded " << pkg->name << "\n";
    } else {
        std::cerr << "Failed to download " << pkg->name << "\n";
        return false;
    }

    std::cout << "Successfully installed " << pkg->name << "\n";
    return true;
}
