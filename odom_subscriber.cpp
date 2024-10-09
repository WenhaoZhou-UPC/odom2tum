#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <iostream>
#include <fstream>
#include <mutex>
//互斥锁
std::mutex file_mutex;
std::ofstream output_file1;
std::ofstream output_file2;
std::ofstream output_file3;
std::ofstream output_file4;
std::ofstream output_file5;
std::ofstream output_file6;
//标志位 
bool data_received_once = false;
bool data_received_once_2 = false;
bool data_received_once_3= false;
bool data_received_once_4= false;
bool data_received_once_5= false;
bool data_received_once_6= false;
void odomCallback1(const geometry_msgs::PoseStamped::ConstPtr & msg) {//订阅PoseStamped消息这是动捕的（刚体几何类型msg)
  std::lock_guard<std::mutex> lock(file_mutex); // 使用互斥锁保护文件操作

  if (!data_received_once) {
    output_file1.open("/home/zhou/odom_test/data/groundtruthA1.txt", std::ios::app);
    data_received_once = true;
    std::cout<< "start groundtruthA1!" << std::endl;
  }
  output_file1<<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
              <<std::setprecision(6) <<msg->pose.position.x << " "
              <<msg->pose.position.y << " "
              <<msg->pose.position.z << " "
              <<msg->pose.orientation.x << " "
              <<msg->pose.orientation.y << " "
              <<msg->pose.orientation.z << " "
              <<msg->pose.orientation.w<< std::endl;   //写入tum格式数据
  std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
void odomCallback2(const geometry_msgs::PoseStamped::ConstPtr & msg) {//订阅PoseStamped消息这是动捕的（刚体几何类型msg)
  std::lock_guard<std::mutex> lock(file_mutex); // 使用互斥锁保护文件操作

  if (!data_received_once_2) {
    output_file2.open("/home/zhou/odom_test/data/A1.txt", std::ios::app);
    data_received_once_2= true;
    std::cout<< "start groundtruthA2!" << std::endl;
  }
  output_file2 <<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
              <<std::setprecision(6) <<msg->pose.position.x << " "
              <<msg->pose.position.y << " "
              <<msg->pose.position.z << " "
              <<msg->pose.orientation.x << " "
              <<msg->pose.orientation.y << " "
              <<msg->pose.orientation.z << " "
              <<msg->pose.orientation.w<< std::endl;   //写入tum格式数据
  std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
void odomCallback3(const geometry_msgs::PoseStamped::ConstPtr & msg) {//订阅PoseStamped消息这是动捕的（刚体几何类型msg)
  std::lock_guard<std::mutex> lock(file_mutex); // 使用互斥锁保护文件操作

  if (!data_received_once_3) {
    output_file3.open("/home/zhou/odom_test/data/groundtruthA3.txt", std::ios::app);
    data_received_once_3= true;
    std::cout<< "start groundtruthA3!" << std::endl;
  }
  output_file3<<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
              <<std::setprecision(6) <<msg->pose.position.x << " "
              <<msg->pose.position.y << " "
              <<msg->pose.position.z << " "
              <<msg->pose.orientation.x << " "
              <<msg->pose.orientation.y << " "
              <<msg->pose.orientation.z << " "
              <<msg->pose.orientation.w<< std::endl;   //写入tum格式数据
  std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
void odomteryCallback1(const nav_msgs::Odometry::ConstPtr & msg){ //订阅odom这是Lio的（是导航的msg）
  std::lock_guard<std::mutex> lock(file_mutex);  //加入互斥锁
  if(!data_received_once_4){
    output_file4.open("/home/zhou/odom_test/data/outputA1.txt", std::ios::app);
    data_received_once_4 = true;
    std::cout<< "start odomteryA1!" << std::endl;
  }
  // 时间戳保留精度3位
   output_file4 <<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
               <<std::setprecision(6) <<msg->pose.pose.position.x <<" "
               <<msg->pose.pose.position.y <<" "
               <<msg->pose.pose.position.z<<" "
               <<msg->pose.pose.orientation.x <<" "
               <<msg->pose.pose.orientation.y <<" "
               <<msg->pose.pose.orientation.z <<" "
               <<msg->pose.pose.orientation.w <<std::endl;  //写入tum格式数据
std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
void odomteryCallback2(const nav_msgs::Odometry::ConstPtr & msg){ //订阅odom这是Lio的（是导航的msg）
  std::lock_guard<std::mutex> lock(file_mutex);  //加入互斥锁
  if(!data_received_once_5){
    output_file5.open("/home/zhou/odom_test/data/outputA2.txt", std::ios::app);
    data_received_once_5 = true;
    std::cout<< "start odomteryA2!" << std::endl;
  }
  // 时间戳保留精度3位
   output_file5 <<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
               <<std::setprecision(6) <<msg->pose.pose.position.x <<" "
               <<msg->pose.pose.position.y <<" "
               <<msg->pose.pose.position.z <<" "
               <<msg->pose.pose.orientation.x <<" "
               <<msg->pose.pose.orientation.y <<" "
               <<msg->pose.pose.orientation.z <<" "
               <<msg->pose.pose.orientation.w <<std::endl;  //写入tum格式数据
std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
void odomteryCallback3(const nav_msgs::Odometry::ConstPtr & msg){ //订阅odom这是Lio的（是导航的msg）
  std::lock_guard<std::mutex> lock(file_mutex);  //加入互斥锁
  if(!data_received_once_6){
    output_file6.open("/home/zhou/odom_test/data/outputA3.txt", std::ios::app);
    data_received_once_6 = true;
    std::cout<< "start odomteryA3!" << std::endl;
  }
  // 时间戳保留精度3位
   output_file6 <<std::fixed<<std::setprecision(5) << msg->header.stamp.toSec() << " "
               <<std::setprecision(6) <<msg->pose.pose.position.x <<" "
               <<msg->pose.pose.position.y <<" "
               <<msg->pose.pose.position.z <<" "
               <<msg->pose.pose.orientation.x <<" "
               <<msg->pose.pose.orientation.y <<" "
               <<msg->pose.pose.orientation.z <<" "
               <<msg->pose.pose.orientation.w <<std::endl;  //写入tum格式数据
std::cout<<std::fixed<<std::setprecision(5)<<msg->header.stamp.toSec()<<std::endl;
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "odom_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/A1_vrpn_client_node/A1/pose", 1000, &odomCallback1);
  ros::Subscriber sub2 = nh.subscribe("/slam_odom", 1000, &odomteryCallback1);
   //ros::Subscriber sub3= nh.subscribe("/A1/poseStamped", 1000, &odomCallback2);
  // ros::Subscriber sub4 = nh.subscribe("/A2/Odometry", 1000, &odomteryCallback2);
  // ros::Subscriber sub5= nh.subscribe("/vrpn_client_node/A3/pose", 1000, &odomCallback3);
  // ros::Subscriber sub6 = nh.subscribe("/A3/Odometry", 1000, &odomteryCallback3);
  ros::spin();

  // 在程序结束前关闭文件
  {
    std::lock_guard<std::mutex> lock(file_mutex);
    if (output_file1.is_open()) {
      output_file1.close();
    }
    if(output_file2.is_open()){
    output_file2.close();
    }
    if (output_file3.is_open()) {
      output_file3.close();
    }
    if(output_file4.is_open()){
    output_file4.close();
    }
    if (output_file5.is_open()) {
    output_file5.close();
    }
    if(output_file6.is_open()){
    output_file6.close();
    }
  }
  return 0;
}