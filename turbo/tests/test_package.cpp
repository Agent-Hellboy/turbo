// test_package.cpp
#include "package.h"
#include <gtest/gtest.h>

TEST(PackageTest, ConstructorInitialization) {
    Package pkg("libA", "1.0", "https://example.com/libA.zip", {"libB"});
    EXPECT_EQ(pkg.name, "libA");
    EXPECT_EQ(pkg.version, "1.0");
    EXPECT_EQ(pkg.source, "https://example.com/libA.zip");
    EXPECT_EQ(pkg.dependencies.size(), 1);
    EXPECT_EQ(pkg.dependencies[0], "libB");
}
