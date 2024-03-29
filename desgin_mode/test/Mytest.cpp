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
#include <gtest/gtest.h>
#include "hello.h"
#include "logger.h"
using namespace std;
TEST(Test_Calc, Test_Calc_Add2_Test)
{
     // 	print log test, you can transfer any param to do format
    	int param = 1;
    	XLOG_TRACE("this is trace log record, param:  {}", ++param ); // int type param is ok
    	XLOG_DEBUG("this is debug log record, param: {}", ++param);
    	XLOG_INFO("this is info log record, param: {}", ++param);
    	XLOG_WARN("this is warn log record, param: {}", double(++param)); // double type param is ok
    	XLOG_ERROR("this is error log record, param: {}", std::to_string(++param)); // string type param is ok
    test111();
   // Shape *shape = new Rectangle();
  //  shape->draw();
    AShape *shape1 = new CircleBridge(100, 100, 10, new GreenCircle());
    shape1->draw();

    std::shared_ptr<string> string = make_shared<std::string>("123123");
    cout << "111:" << *string << endl;
    cout << "address:" << string << endl;
    cout << "address:" << &string << endl;
    cout << string.use_count() << endl;
    cout << string.use_count() << endl;
    int a = 0;
    //int a = Calc::Add(3, 5);
    EXPECT_TRUE(8 == 8);
    //EXPECT_TRUE(6==8);
}



TEST(Test_Calc, Test_Calc_Add3_Test)
{

}