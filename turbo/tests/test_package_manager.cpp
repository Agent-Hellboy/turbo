// test_package_manager.cpp
#include "package_manager.h"
#include "repository.h"
#include "package.h"
#include <gtest/gtest.h>

TEST(PackageManagerTest, InstallPackageWithoutDependencies) {
    Repository repo;
    Package pkg("libA", "1.0", "https://example.com/libA.zip", {});
    repo.addPackage(pkg);

    PackageManager pkgManager(repo);
    EXPECT_TRUE(pkgManager.install("libA"));
}

TEST(PackageManagerTest, InstallPackageWithDependencies) {
    Repository repo;
    Package pkgA("libA", "1.0", "https://example.com/libA.zip", {"libB"});
    Package pkgB("libB", "1.1", "https://example.com/libB.zip", {});
    repo.addPackage(pkgA);
    repo.addPackage(pkgB);

    PackageManager pkgManager(repo);
    EXPECT_TRUE(pkgManager.install("libA"));
}
