#!/bin/bash
# t is executable program

g++ -g -O0 a.cc -o t
valgrind --tool=memcheck --log-file=all_ret.txt ./t
valgrind --tool=memcheck --leak-check=yes --log-file=leak_ret.txt ./t
