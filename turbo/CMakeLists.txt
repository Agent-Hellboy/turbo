# Set the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project
project(TurboPackageManager VERSION 1.0 DESCRIPTION "A C++ Package Manager" LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directories
include_directories(include)

# Find required libraries
find_package(CURL REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(GTest REQUIRED)

# Define 'turbo_lib' as a library for shared usage
add_library(turbo_lib
    src/package.cpp
    src/package_manager.cpp
    src/repository.cpp
    src/utils.cpp
    src/yaml_parser.cpp
)

# Link required libraries to 'turbo_lib'
target_link_libraries(turbo_lib CURL::libcurl yaml-cpp::yaml-cpp)

# Create the main executable target using 'turbo_lib'
add_executable(turbo src/main.cpp)
target_link_libraries(turbo turbo_lib)

# Enable testing
enable_testing()


# Define test executable and link to 'turbo_lib' and Google Test
add_executable(tests
    tests/test_main.cpp
    tests/test_package.cpp
    tests/test_repository.cpp
    tests/test_package_manager.cpp
)
target_link_libraries(tests turbo_lib GTest::GTest GTest::Main)

# Register tests with CTest
add_test(NAME TurboTests COMMAND tests)

# Set output directories for organized builds
set_target_properties(turbo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
set_target_properties(tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add compiler flags for better debugging information
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(turbo PRIVATE -g -O0)
    target_compile_options(tests PRIVATE -g -O0)
else()
    target_compile_options(turbo PRIVATE -O2)
    target_compile_options(tests PRIVATE -O2)
endif()

# Installation instructions (optional)
install(TARGETS turbo DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
