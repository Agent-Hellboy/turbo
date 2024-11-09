#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>

class Package {
public:
    std::string name;
    std::string version;
    std::string source;               // Add this line for source URL
    std::vector<std::string> dependencies;

    Package(const std::string& name, const std::string& version, const std::string& source,
            const std::vector<std::string>& dependencies);
    
};

#endif
