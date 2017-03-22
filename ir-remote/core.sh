#!/bin/bash
echo "kill core"
sudo kill $(pidof core)
echo "start core"
if true ; then
	sudo cat << EOF > /home/pi/robot3/config/core
1
EOF
fi
#sudo echo "1" > /home/pi/robot3/config/core
sudo /home/pi/robot3/src/core/core