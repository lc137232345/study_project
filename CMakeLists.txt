cmake_minimum_required(VERSION 3.1)
PROJECT(MyDEMO)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -lpthread")
set(CMAKE_CXX_STANDARD 11)
include_directories(include)
aux_source_directory(src DIR_SRC)

link_directories(/usr/local/lib/)
#add_executable(demo ${DIR_SRC})
add_library(demo STATIC ${DIR_SRC})
target_link_libraries(demo pthread)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

