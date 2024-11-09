# Turbo

Hehe , I don't want to share what this is.

## Installation Instructions

1. Ensure you have `yaml-cpp` , `googletest`, and `libcurl` installed on your system.

2. Create a build directory, configure the project, and build it:

   ```bash
   mkdir -p build && cd build
   cmake -DCMAKE_PREFIX_PATH="/usr/local" ../turbo
   make

## Uses


- Use Turbo: The turbo binary will be generated inside build/bin and is ready for use.

- Run Tests: To execute tests, use ctest in the build directory:
