#########################################################################
# File Name: record_data.sh
# Author: csgec
# mail: 12345678@qq.com
# Created Time: 2021年06月04日 星期五 11时18分55秒
#########################################################################
#!/bin/bash

rosbag record /test_name /test_index --duration=10 -o out
