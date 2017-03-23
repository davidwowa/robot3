#!/bin/bash
echo "test display 2"
sudo kill $(pidof python)
python /home/pi/Pimoroni/scrollphat/examples/life.py &