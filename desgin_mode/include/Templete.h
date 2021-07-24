/*
 * @Author: your name
 * @Date: 2021-07-19 18:33:29
 * @LastEditTime: 2021-07-19 18:45:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/Templete.h
 */
#include "public.h"
class AbstractClass
{
public:
    virtual void TemplateMethod() final
    {
        PrimitiveOperation1();
        PrimitiveOperation2();
    };
    virtual ~AbstractClass() = default;

protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

class ConcreteClassA : public AbstractClass
{
    virtual void PrimitiveOperation1()
    {
        std::cout << "ConcreteA Operation1" << std::endl;
    }
    virtual void PrimitiveOperation2()
    {
        std::cout << "ConcreteA Operation2" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass
{
    virtual void PrimitiveOperation1()
    {
        std::cout << "ConcreteB Operation1" << std::endl;
    }
    virtual void PrimitiveOperation2()
    {
        std::cout << "ConcreteB Operation2" << std::endl;
    }
};