cmake_minimum_required(VERSION 3.1)
PROJECT(MyDEMO)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -lpthread")
include_directories(include)
aux_source_directory(src DIR_SRC)
# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(cmake_c_standard_required on)
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

link_directories(/usr/local/lib/)
add_executable(demo ${DIR_SRC})
#add_library(demo STATIC ${DIR_SRC})
target_link_libraries(demo pthread)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

