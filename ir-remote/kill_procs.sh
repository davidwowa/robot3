#!/bin/bash
echo "kill all processes"
echo "kill core"
sudo kill $(pidof core)
echo "kill drive_backward"
sudo kill $(pidof drive_backward)
echo "kill drive_forward"
sudo kill $(pidof drive_forward)
echo "kill turn_right"
sudo kill $(pidof turn_right)
echo "kill drive_left"
sudo kill $(pidof turn_left)
echo "kill stop"
sudo kill $(pidof stop)
echo "kill test_motors"
sudo kill $(pidof test_motors)
echo "kill test_motors_2"
sudo kill $(pidof test_motors_2)
echo "kill test_motors_2"
sudo kill $(pidof python)

echo "stop driving"
sudo /home/pi/robot3/src/test_units/drive/stop