#!/bin/bash
echo "compile servo"
g++ servo.cpp -o servo -lwiringPiDev -lwiringPi -lpthread