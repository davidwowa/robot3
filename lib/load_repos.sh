#!/bin/bash
echo "load sonar library"
git clone https://github.com/davidwowa/HC-SR04-Raspberry-Pi-C-.git

echo "load wiringPi library"
git clone https://github.com/davidwowa/WiringPi.git
#echo "install wiringPi"
# only first time
#cd WiringPi
#git pull origin
#cd WiringPi
#./build
#cd ../..