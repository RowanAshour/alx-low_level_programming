#!/bin/bash

# Compile all .c files in the current directory into a dynamic library
gcc -Wall -Werror -pedantic -Wextra -fPIC -c *.c
gcc -shared -o liball.so *.o

# Clean up object files
rm -f *.o

