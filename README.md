<!--
 * @Author: your name
 * @Date: 2021-07-07 07:03:55
 * @LastEditTime: 2021-07-07 07:46:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/README.md
-->

# study_project

## 2021/07/07

### 1.Cmake 添加动态库

link_directories(/usr/local/lib/) 添加库的目录
add_executable(demo ${DIR_SRC}) 生成运行文件
target_link_libraries(demo pthread) 链接静态库


cmake 生成静态库和动态库

### 2.Cmake 制作动态库

指令：add_library()
动态库

add_library(hello SHARED hello.c 1.c 2.c ...)

通过关键字 SHARED 生成动态库：libhello.so
静态库

### 3.Cmake 制作静态库

add_library(hello STATIC hello.c 1.c 2.c ...)

通过关键字 STATIC 生成静态库：libhello.a\

## ## 2021/07/08

### 1.学习一个LOG模块