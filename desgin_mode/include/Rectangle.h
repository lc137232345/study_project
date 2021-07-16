/*
 * @Author: your name
 * @Date: 2021-07-14 18:09:36
 * @LastEditTime: 2021-07-15 18:46:25
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
    Rectangle() = default;
    Rectangle(const std::string &name) : m_strData(name)
    {
        std::cout << "ue_conn_unit_state" << endl;
    }

    ~Rectangle() { cout << "~Rectangle()" << endl; }

private:
    string m_strData;
};
#endif //