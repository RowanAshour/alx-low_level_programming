#!/bin/bash
# This script compiles all .c files in the current directory into .o files and then creates a static library from them.

# Compile all .c files into .o files
gcc -Wall -Wextra -pedantic -c *.c

# Create a static library from all .o files
ar -rc liball.a *.o
