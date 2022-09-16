#!/bin/sh
clear
# flags="-O3"
flags="-Og -g3"
gcc main.c -std=c11 -Wall -Wextra -Wpedantic -lm $flags -o main.out
