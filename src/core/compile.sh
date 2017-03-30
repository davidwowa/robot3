#!/bin/bash
g++ core.cpp ../drive/drive.cpp ../sonar/sonar.cpp ../servo/servo.cpp -o core -lwiringPi -lpthread ../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp
