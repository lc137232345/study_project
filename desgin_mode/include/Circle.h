/*
 * @Author: your name
 * @Date: 2021-07-14 18:17:19
 * @LastEditTime: 2021-07-14 18:48:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/Circle.h
 */
#ifndef _Circle_H_
#define _Circle_H_

#include "shape.h"
class Circle : public Shape
{
public:
    void draw();
    ~Circle() { cout << "~Circle()" << endl; }
};
#endif