#include "yaml_parser.h"
#include <yaml-cpp/yaml.h>

std::vector<Package> parsePackagesFromYAML(const std::string& filePath) {
    std::vector<Package> packages;
    YAML::Node config = YAML::LoadFile(filePath);

    for (const auto& pkgNode : config["packages"]) {
        std::string name = pkgNode["name"].as<std::string>();
        std::string version = pkgNode["version"].as<std::string>();
        std::string source = pkgNode["source"].as<std::string>();  // Get source from YAML
        std::vector<std::string> dependencies;
        
        if (pkgNode["dependencies"]) {
            for (const auto& dep : pkgNode["dependencies"]) {
                dependencies.push_back(dep.as<std::string>());
            }
        }

        packages.emplace_back(name, version, source, dependencies);
    }

    return packages;
}
