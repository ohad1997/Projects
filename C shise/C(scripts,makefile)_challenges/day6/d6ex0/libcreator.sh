#!/bin/sh
cd /home/ohad/Documents/cprojects/day6

gcc -c d6ex0.c d6ex0.o
ar -rcs libft.a d6ex0.o

gcc main.c -L/home/ohad/Documents/cprojects/day6/d6ex0 -lft -o main

