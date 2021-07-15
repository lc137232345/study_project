/*
 * @Author: your name
 * @Date: 2021-07-14 18:23:25
 * @LastEditTime: 2021-07-15 05:02:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/src/ShapeFactory.cpp
 */
#include "ShapeFactory.h"

std::shared_ptr<Shape> ShapeFactory::GetShape(std::string name)
{
    if (name == "")
    {
        return nullptr;
    }
    if (name == "CIRCLE")
    {
        return std::shared_ptr<Shape>(new Circle);
    }
    else if (name == "RECTANGLE")
    {
        return std::shared_ptr<Shape>(new Rectangle);
    }
    else if (name == "SQUARE")
    {
        return std::shared_ptr<Shape>(new Square);
    }
    return nullptr;
}