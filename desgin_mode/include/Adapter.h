/*
 * @Author: your name
 * @Date: 2021-07-16 23:23:18
 * @LastEditTime: 2021-07-16 23:40:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/Adapter.h
 */
#include "public.h"

//产品类
class CElectricity
{
public:
    virtual void charge()
    {
        std::cout << "this is 220V..." << std::endl;
    }
};

//适配器类
class Adapter5V
{
public:
    void transfer()
    {
        cout << "this is 5V..." << endl;
    }
    ~Adapter5V() { cout << "~Adapter5V()" << endl; }
};

//采用组合的方式，实现代码复用
class Elecwith5V : public CElectricity
{
public:
    Elecwith5V() : p_adapter(NULL)
    {
        p_adapter = make_shared<Adapter5V>();
    }
    void charge() override
    {
        p_adapter->transfer();
    }
    ~Elecwith5V() { cout << "~Elecwith5V()" << endl; }

private:
    shared_ptr<Adapter5V> p_adapter;
};