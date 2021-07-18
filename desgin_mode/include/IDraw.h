/*
 * @Author: your name
 * @Date: 2021-07-17 07:39:53
 * @LastEditTime: 2021-07-18 07:27:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/IDraw.h
 */
#include "public.h"
class IDraw
{
public:
    virtual void drawCircle(int radius, int x, int y) = 0;

    virtual ~IDraw() = default;
};

class RedCircle : public IDraw
{
public:
    void drawCircle(int radius, int x, int y) override
    {
        std::cout << "/* RedCircle draw */" << std::endl;
    }
};

class GreenCircle : public IDraw
{
public:
    void drawCircle(int radius, int x, int y) override
    {
        std::cout << "/* GreenCircle draw */" << std::endl;
    }
};
#if 1
class AShape
{
protected:
    shared_ptr<IDraw> ptIdraw;

public:
    AShape() = default;
    AShape(IDraw *ptIDraw)
    {
        ptIdraw.reset(ptIDraw);
    };

    virtual void draw() = 0;
    ~AShape()
    {
        cout << "~AShape" << endl;
    };
};

class CircleBridge : public AShape
{
private:
    int x, y, radius;

public:
    CircleBridge(int x, int y, int radius, IDraw *drawAPI) : AShape(drawAPI), x(x), radius(radius), y(y)
    {
    }

    void draw()
    {
        ptIdraw->drawCircle(radius, x, y);
    }

    ~CircleBridge(){};
};
#endif