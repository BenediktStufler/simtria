#!/bin/bash

gcc src/simtria.c -O2 -Wall -o bin/simtria -pthread  -lgsl -lmpfr 
