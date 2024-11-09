#include "package.h"

Package::Package(const std::string& name, const std::string& version, const std::string& source,
                 const std::vector<std::string>& dependencies)
    : name(name), version(version), source(source), dependencies(dependencies) {}

