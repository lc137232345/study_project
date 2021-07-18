<!--
 * @Author: your name
 * @Date: 2021-07-07 07:03:55
 * @LastEditTime: 2021-07-18 16:51:49
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



1、 不要传递shared_ptr本身，而是用原始指针。因为会有性能损失，原子操作的自增自减等。

使用f(widget *w)

不使用f(shared_ptr< widget > w)

函数的返回值也是同样的道理。

2当表示所有权的转移时，用unique_ptr作为函数参数。



虚函数的话，基类需要有实现；
			纯虚类的话，可以没有实现;
			
			
2. shared_ptr 传递 的话 ，优先 RAW_PTR,  利用reset函数接受参数。			
