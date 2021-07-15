/*
 * @Author: your name
 * @Date: 2021-07-14 18:30:48
 * @LastEditTime: 2021-07-14 19:25:48
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
#include "ShapeFactory.h"
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
std::shared_ptr<Shape> test()
{
    ShapeFactory *shapeFactory = new ShapeFactory();
    std::shared_ptr<Shape> shape = shapeFactory->GetShape("CIRCLE");
    shape->draw();

    std::shared_ptr<Shape> shape1 = shapeFactory->GetShape("RECTANGLE");
    shape1->draw();

    std::shared_ptr<Shape> shape2 = shapeFactory->GetShape("SQUARE");
    shape2->draw();

    delete shapeFactory;

    cout << shape.use_count() << endl;
    cout << shape1.use_count() << endl;
    cout << shape2.use_count() << endl;

    return shape;
}
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
#endif
    shared_ptr<Shape> shape = test();
    shared_ptr<string> name = make_shared<string>("12313");
    cout << *name << endl;
    shape->draw();
    return 0;
}

/*线程之间共享资源stdout*/
