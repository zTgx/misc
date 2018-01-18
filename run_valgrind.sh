#!/bin/bash
# t is executable program

valgrind --tool=memcheck --log-file=all_ret.txt ./t
valgrind --tool=memcheck --leak-check=yes --log-file=leak_ret.txt ./t
