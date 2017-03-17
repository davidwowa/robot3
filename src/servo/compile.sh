#!/bin/bash
echo "compile servo"
g++ servo.cpp -o servo -lwiringPi -lpthread