/*
 * @Author: your name
 * @Date: 2021-07-14 18:09:36
 * @LastEditTime: 2021-07-14 19:07:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/Rectangle.h
 */
#ifndef _Rectangle_H_
#define _Rectangle_H_
#include "shape.h"
class Rectangle : public Shape
{
public:
    void draw();

    ~Rectangle() { cout << "~Rectangle()" << endl; }
};
#endif //