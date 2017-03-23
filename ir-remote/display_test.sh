#!/bin/bash
echo "test display"
sudo kill $(pidof python)
python /home/pi/Pimoroni/scrollphat/examples/life.py &