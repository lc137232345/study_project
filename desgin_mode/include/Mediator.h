/*
 * @Author: your name
 * @Date: 2021-07-24 00:08:06
 * @LastEditTime: 2021-07-24 00:18:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/123.h
 */
#include "public.h"
#include <string>
using namespace std;
class Mediator;
//抽象人
class Person
{
protected:
    Mediator *m_mediator; //中介
public:
    virtual void SetMediator(Mediator *mediator) = 0; //设置中介
    virtual void SendMessage(string message) = 0;     //向中介发送信息
    virtual void GetMessage(string message) = 0;
    virtual ~Person()
    {
        cout << "~Person" << endl;
    }; //从中介获取信息
};
//抽象中介机构
class Mediator
{
public:
    virtual void Send(string message, Person *person) = 0;
    virtual void SetA(Person *A) = 0; //设置其中一方
    virtual void SetB(Person *B) = 0;
    virtual ~Mediator()
    {
        cout << "~Mediator" << endl;
    }; //从中介获取信息
};
//租房者
class Renter : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "租房者收到信息" << message; }
    virtual ~Renter()
    {
        cout << "~Renter" << endl;
    };
};
//房东
class Landlord : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "房东收到信息：" << message; }
    virtual ~Landlord()
    {
        cout << "~Landlord" << endl;
    };
};
//房屋中介
class HouseMediator : public Mediator
{
private:
    Person *m_A; //租房者
    Person *m_B; //房东
public:
    HouseMediator() : m_A(0), m_B(0) {}
    void SetA(Person *A) { m_A = A; }
    void SetB(Person *B) { m_B = B; }
    void Send(string message, Person *person)
    {
        if (person == m_A)            //租房者给房东发信息
            m_B->GetMessage(message); //房东收到信息
        else
            m_A->GetMessage(message);
    }
};
