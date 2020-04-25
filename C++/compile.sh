#!/bin/bash

g++ -std=c++14 -Wno-deprecated-declarations -fconcepts -Wall -o compile/$1 $1.cpp
