#!/bin/bash
echo "test display 2"
sudo kill $(pidof python)
python /home/pi/Pimoroni/scrollphat/examples/scroll-text-once.py TEST &