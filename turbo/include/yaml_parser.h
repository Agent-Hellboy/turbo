#ifndef YAML_PARSER_H
#define YAML_PARSER_H

#include "package.h"
#include <vector>
#include <string>

std::vector<Package> parsePackagesFromYAML(const std::string& filePath);

#endif
