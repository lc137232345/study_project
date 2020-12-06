/*
 * @Author: your name
 * @Date: 2020-12-05 06:34:10
 * @LastEditTime: 2020-12-06 05:43:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /code/study_project/fsm_study/src/main.cpp
 */
#include <iostream>
#include "demo.h"
int main(int argc, char const *argv[])
{
    ue_conn_state *ue_conn_stat = new ue_conn_state;

    const double pi = 3.14;

    const double *cptr = &pi;
    double dval = 12.5;
    cptr = &dval;
    ue_conn_stat->get_current_state()->show_A();
    std::cout
        << "/* message */" << std::endl;
    return 0;
}
