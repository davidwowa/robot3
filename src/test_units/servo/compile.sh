#!/bin/bash
echo "compile servo"
g++ servo.cpp -o servo -lwiringPi -lpthread
g++ servo_test.cpp -o servo_test -lwiringPi -lpthread
