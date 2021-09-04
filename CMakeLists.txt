# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.1)

# 项目信息
project (Demo3)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(cmake_c_standard_required on)
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 14)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(${PROJECT_SOURCE_DIR}/desgin_mode/include)
include_directories(${PROJECT_SOURCE_DIR}/pub/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/include/)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)

find_package(Threads)
# 添加子目录
add_subdirectory(desgin_mode)
# 指定生成目标 
add_executable(Demo ${DIR_SRCS})
# 添加链接库
TARGET_LINK_LIBRARIES(Demo DESIGN ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(Demo pthread)

