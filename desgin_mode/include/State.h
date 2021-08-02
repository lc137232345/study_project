/*
 * @Author: your name
 * @Date: 2021-07-26 08:22:40
 * @LastEditTime: 2021-07-30 06:31:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/State.h
 */
#include "public.h"

class BaseState
{

public:
    virtual ~BaseState() = default;
    virtual void doAction1()
    {
        cout << "BaseState doAction1" << endl;
    };
    virtual void doAction2()
    {
        cout << "BaseState doAction2" << endl;
    };
    virtual void doAction3()
    {
        cout << "BaseState doAction3" << endl;
    };
};

class RRC_SETUP_REQUEST : public BaseState
{
public:
    virtual ~RRC_SETUP_REQUEST() = default;
    virtual void doAction3() override
    {
        cout << "RRC_SETUP doAction3" << endl;
    }
};

class RRC_SETUP : public BaseState
{
public:
    virtual ~RRC_SETUP() = default;
    virtual void doAction1() override
    {
        cout << "RRC_SETUP doAction1" << endl;
    }
};

class RRC_SETUP_COMPLETE : public BaseState
{
public:
    virtual ~RRC_SETUP_COMPLETE() = default;
    virtual void doAction2() override
    {
        cout << "RRC_SETUP_COMPLETE doAction1" << endl;
    }
};

class Context
{
public:
    Context(/* args */);
    static BaseState *m_instance;
    static BaseState *getInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new RRC_SETUP_REQUEST();
        }
        return m_instance;
    }

    void setState(BaseState *state)
    {
        this->m_instance = state;
    }
    ~Context();
};
BaseState *Context::m_instance = nullptr;

Context::Context(/* args */)
{
}

Context::~Context()
{
}
