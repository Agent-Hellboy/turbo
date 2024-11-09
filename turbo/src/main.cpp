#include <iostream>
#include "package_manager.h"
#include "yaml_parser.h"
#include <yaml-cpp/yaml.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 3 || std::string(argv[1]) != "install") {
        std::cerr << "Usage: turbo install <yaml-file>" << std::endl;
        return 1;
    }

    std::string yamlFile = argv[2];  // Use argv[2] as the YAML file path

    try {
        // Load packages from the YAML file and populate the repository
        Repository repo;
        auto packages = parsePackagesFromYAML(yamlFile);  // Parse YAML to populate the repository
        for (const auto& pkg : packages) {
            repo.addPackage(pkg);
        }

        PackageManager pkgManager(repo);

        // Install each package
        for (const auto& pkg : packages) {
            pkgManager.install(pkg.name);
        }
    } catch (const YAML::BadFile& e) {
        std::cerr << "Error: Unable to open YAML file '" << yamlFile << "'." << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
