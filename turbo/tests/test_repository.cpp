// test_repository.cpp
#include "repository.h"
#include "package.h"
#include <gtest/gtest.h>

TEST(RepositoryTest, AddAndGetPackage) {
    Repository repo;
    Package pkg("libA", "1.0", "https://example.com/libA.zip", {});
    repo.addPackage(pkg);

    auto retrieved_pkg = repo.getPackage("libA");
    ASSERT_TRUE(retrieved_pkg != nullptr);
    EXPECT_EQ(retrieved_pkg->name, "libA");
    EXPECT_EQ(retrieved_pkg->version, "1.0");
}
