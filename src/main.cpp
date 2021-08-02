/*
 * @Author: your name
 * @Date: 2021-07-14 18:30:48
 * @LastEditTime: 2021-08-02 04:57:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/src/main.cpp
 */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex>
#if 1
#include "ShapeFactory.h"
#include "Singleton.h"
#include "Adapter.h"
#endif
#include "IDraw.h"
#include "Templete.h"
#include "Mediator.h"
#include "Proxy.h"
#include "State.h"
std::mutex mutex1; //定义锁

void *tfn(void *arg)
{

    while (1)
    {
        std::lock_guard<std::mutex> lock(mutex1);

        printf("hello ");
        sleep(1); /*模拟长时间操作共享资源，导致cpu易主，产生与时间有关的错误*/
        printf("world\n");

        sleep(1); //睡眠，释放cpu
    }

    return NULL;
}
shared_ptr<Shape> test()
{
    ShapeFactory *shapeFactory = new ShapeFactory();
    std::shared_ptr<Shape> shape = shapeFactory->GetShape("CIRCLE");
    shape->draw();

    std::shared_ptr<Shape> shape1 = shapeFactory->GetShape("RECTANGLE", "123");
    shape1->draw();

    std::shared_ptr<Shape> shape2 = shapeFactory->GetShape("SQUARE");
    shape2->draw();

    delete shapeFactory;

    cout << shape.use_count() << endl;
    cout << shape1.use_count() << endl;
    cout << shape2.use_count() << endl;

    return shape1;
};

void test1(std::shared_ptr<string> &string)
{
    cout << "222:" << *string << endl;
    cout << "address:" << string << endl;
    cout << "address:" << &string << endl;
    cout << string.use_count() << endl;
}

class MyClass
{
public:
    MyClass() = default;
    MyClass(const string &strData) : m_strData(strData)
    {
        cout << "构造函数" << endl;
        ptstring = make_shared<string>(strData);
        cout << ptstring.use_count() << endl;
        cout << m_strData.data() << endl;
    };
    MyClass(const MyClass &other)
    {
        std::cout << "MyClass(const MyClass &other)" << std::endl;
        cout << ptstring.use_count() << endl;
        m_strData = other.m_strData;
        std::cout << "MyClass(const MyClass &other)" << std::endl;
        ptstring = make_shared<string>(*(other.ptstring));
        // ptstring = other.ptstring;
        cout << ptstring.use_count() << endl;
    }
    MyClass &operator=(const MyClass &other)
    {
        cout << "拷贝赋值函数" << endl;
        m_strData = other.m_strData;
        cout << ptstring.use_count() << endl;
        cout << "拷贝赋值函数" << endl;
        ptstring = other.ptstring;
        //  ptstring = make_shared<string>(*(other.ptstring));
        cout << ptstring.use_count() << endl;
        return *this;
    }
    shared_ptr<string> &Getptstring()
    {
        return ptstring;
    }
    ~MyClass()
    {
        cout << "~destory" << endl;
        cout << ptstring.use_count() << endl;
    };

private:
    string m_strData;
    shared_ptr<string> ptstring;
};

int main(void)
{
#if 0
    pthread_t tid;

    pthread_create(&tid, NULL, tfn, NULL);
    while (1)
    {
        std::unique_lock<std::mutex> lock(mutex);
        printf("HELLO ");
        sleep(1);
        printf("WORLD\n");
        lock.unlock();
        sleep(1);
    }

    auto shape = test();
    shape->draw();

    auto pClass = Magic_Singleton<MyClass>::Getinstance("21");
    Magic_Singleton<MyClass>::DesInstance();

    cout << "适配器模式" << endl;

    auto entity = make_shared<Elecwith5V>();
    entity->charge();

    cout << "桥接模式" << endl;

    // shared_ptr<AShape> shape = make_shared<CircleBridge>(100, 100, 10, new RedCircle());
    AShape *shape1 = new CircleBridge(100, 100, 10, new GreenCircle());
    shape1->draw();

    std::shared_ptr<string> string = make_shared<std::string>("123123");
    cout << "111:" << *string << endl;
    cout << "address:" << string << endl;
    cout << "address:" << &string << endl;
    cout << string.use_count() << endl;
    test1(string);
    cout << string.use_count() << endl;

    cout << "模板模式" << endl;
    shared_ptr<AbstractClass> abstractClass = make_shared<ConcreteClassA>();
    abstractClass->TemplateMethod();
    shared_ptr<AbstractClass> abstractClass2 = make_shared<ConcreteClassB>();
    abstractClass2->TemplateMethod();

    cout << "中介者模式" << endl;
    shared_ptr<Mediator> mediator = make_shared<HouseMediator>();
    shared_ptr<Person> person1 = make_shared<Renter>();
    shared_ptr<Person> person2 = make_shared<Landlord>();
    mediator->SetA(person1.get());
    mediator->SetB(person2.get());
    person1->SetMediator(mediator.get());
    person2->SetMediator(mediator.get());
    person1->SendMessage("我想在南京路附近租套房子，价格800元一个月\n");
    person2->SendMessage("出租房子：南京路100号，70平米，1000元一个月\n");

    cout << "代理模式" << endl;
    shared_ptr<Iimage> image = make_shared<Proxy>("test_10mb.jpg");

    image->display();
    cout << endl;
    image->display();

    cout << "状态模式" << endl;
    Context context;
    context.getInstance()->doAction1();
    context.getInstance()->doAction2();
    context.getInstance()->doAction3();
    RRC_SETUP_COMPLETE *rrc = new RRC_SETUP_COMPLETE();
    context.setState(rrc);
    context.getInstance()->doAction1();
    context.getInstance()->doAction2();
    context.getInstance()->doAction3();
#endif
    cout << "拷贝赋值函数测试" << endl;
    MyClass *myClass = new MyClass("132");
    MyClass myClass1 = *myClass;
    cout << myClass1.Getptstring().use_count() << endl;
    MyClass myClass2;
    myClass2 = *myClass;
    delete myClass;

    return 0;
}

/*线程之间共享资源stdout*/
