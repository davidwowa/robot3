#!/bin/bash
echo "compile core"
cd /home/pi/robot3/src/core/
./compile.sh

echo "compile sonar test"
cd /home/pi/robot3/src/test_units/sonar/
./compile.sh

echo "compile drive test"
cd /home/pi/robot3/src/test_units/drive/
./compile.sh

echo "compile file io test"
cd /home/pi/robot3/src/test_units/io/
./compile.sh

echo "compile ip address test"
cd /home/pi/robot3/src/test_units/net/
./compile.sh

echo "ready"