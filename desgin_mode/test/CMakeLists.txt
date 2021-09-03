cmake_minimum_required(VERSION 3.6)
 
# 需包含的头文件
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
# 需包含的库文件
link_directories(
   # ${PROJECT_BINARY_DIR}/lib
    /usr/lib/gtest
)

find_package(Threads)

AUX_SOURCE_DIRECTORY(. DIR_SRC_TESTS)
add_executable(test_sult ${DIR_SRC_TESTS})
TARGET_LINK_LIBRARIES(test_sult gtest gtest_main)
 
TARGET_LINK_LIBRARIES(test_sult ${CMAKE_THREAD_LIBS_INIT})
 
#这个必须放在project的后面
IF(MSVC)
   message("run here")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()
