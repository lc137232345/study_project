/*
 * @Author: your name
 * @Date: 2021-07-14 18:20:59
 * @LastEditTime: 2021-07-15 05:06:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/ShapeFactory.h
 */
#ifndef _ShapeFactory_H_
#define _ShapeFactory_H_
#include "shape.h"
#include "string"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
class ShapeFactory
{
public:
    std::shared_ptr<Shape> GetShape(std::string shapeType);

    ~ShapeFactory() { cout << "~ShapeFactory()" << endl; }
};

#endif