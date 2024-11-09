// test_main.cpp
#include "yaml_parser.h"
#include "repository.h"
#include "package_manager.h"
#include <gtest/gtest.h>
#include <fstream>

// Helper function to create a temporary YAML file
void createTestYAMLFile(const std::string& filePath) {
    std::ofstream file(filePath);
    file << "packages:\n"
         << "  - name: libA\n"
         << "    version: '1.0'\n"
         << "    source: 'https://example.com/libA.zip'\n";
    file.close();
}

TEST(MainTest, InstallPackagesFromYAML) {
    std::string testFile = "test_packages1.yml";
    createTestYAMLFile(testFile);

    Repository repo;
    auto packages = parsePackagesFromYAML(testFile);
    for (const auto& pkg : packages) {
        repo.addPackage(pkg);
    }

    PackageManager pkgManager(repo);
    EXPECT_TRUE(pkgManager.install("libA"));

    // Clean up
    std::remove(testFile.c_str());
}
