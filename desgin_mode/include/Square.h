/*
 * @Author: your name
 * @Date: 2021-07-14 18:15:15
 * @LastEditTime: 2021-07-14 19:07:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/Square.h
 */
#ifndef _Square_H_
#define _Square_H_
#include "shape.h"
class Square : public Shape
{
public:
    void draw();
    ~Square() { cout << "~Square()" << endl; }
};
#endif //