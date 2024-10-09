use catkin_ws
```bash
mkdir catkin_ws
cd catkin_ws
mkdir src
```
create rospkg
```bash
catkin_create_pkg odom2txt roscpp std_msgs
```
cp cpp to odom2txt/src/
cp CmakeLists.txt to odom2txt/

```bash
cd catkin_ws
catkin_make
```
run
```
rosrun odom2txt odom_subscriber
```
