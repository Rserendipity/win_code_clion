cmake_minimum_required(VERSION 3.22)    #不用理会
project(3_1)   # 也不用理会 是你的工程名字

set(CMAKE_CXX_STANDARD 11)  #自动生成的 不用管
#**************************************
include_directories("C:/Program Files/MySQL/MySQL Server 8.0/include")  #添加include的路径
link_directories("C:/Program Files/MySQL/MySQL Server 8.0/lib")     #添加lib路径
link_libraries(libmysql.dll)
#**************************************
add_executable(3_1 main.cpp test/test_user_log.cpp test/test_user_log.h)

target_link_libraries(3_1 libmysql.dll)        #链接对应的库到本工程
