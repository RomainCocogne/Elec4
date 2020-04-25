#!/bin/bash

g++ -std=c++14 -O1 -Wno-deprecated-declarations -fconcepts -Wall -pedantic -o compile/$1 $1.cpp

name=$1
shift
param=$*
if [[ $1 == "-v" ]]; then
	shift
	valgrind --leak-check=full --track-origins=yes compile/$name $param 
else 
	compile/$name $param 
fi
