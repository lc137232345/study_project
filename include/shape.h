/*
 * @Author: your name
 * @Date: 2021-07-14 18:05:55
 * @LastEditTime: 2021-07-14 19:07:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/shape.cpp
 */
#ifndef _Shape_H_
#define _Shape_H_

#include "iostream"
#include <memory>
using namespace std;
class Shape
{

public:
    virtual void draw() = 0;
};
#endif
