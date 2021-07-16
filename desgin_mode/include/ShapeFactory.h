/*
 * @Author: your name
 * @Date: 2021-07-14 18:20:59
 * @LastEditTime: 2021-07-15 22:39:45
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
    template <typename... Args>
    std::shared_ptr<Shape> GetShape(std::string name, Args &&...args);

    ~ShapeFactory() { cout << "~ShapeFactory()" << endl; }
};

template <typename... Args>
std::shared_ptr<Shape> ShapeFactory::GetShape(std::string name, Args &&...args)
{
    if (name == "")
    {
        return nullptr;
    }
    if (name == "CIRCLE")
    {
        return std::make_shared<Circle>();
    }
    else if (name == "RECTANGLE")
    {
        return std::make_shared<Rectangle>(std::forward<Args>(args)...);
        //return std::shared_ptr<Shape>(new Rectangle);
    }
    else if (name == "SQUARE")
    {
        return std::make_shared<Square>();
        // return std::shared_ptr<Shape>(new Square);
    }
    return nullptr;
};
#endif