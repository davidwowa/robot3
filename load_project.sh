#!/bin/bash
sudo rm -r robot3
git clone https://bitbucket.org/wowa_/robot3
chmod +x /home/pi/robot3/deploy.sh
cd /home/pi/robot3
/home/pi/robot3/deploy.sh