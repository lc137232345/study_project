/*
 * @Author: your name
 * @Date: 2020-12-05 06:26:16
 * @LastEditTime: 2020-12-05 08:01:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /code/study_project/fsm_study/src/demo.cpp
 */
#include <iostream>
#include "demo.h"
#if 1
void ue_conn_state::ue_conn_idle::show_A()
{
    std::cout << "/* ue_conn_state::ue_conn_idle::show_A */" << std::endl;
};
void ue_conn_state::ue_conn_idle::show_C()
{
    std::cout << "/* ue_conn_state::ue_conn_idle::show_C() */" << std::endl;
}

void ue_conn_state::ue_conn_connected::show_C()
{
    std::cout << "/* ue_conn_state::ue_conn_connected::show_C() */" << std::endl;
}

void ue_conn_state::ue_conn_connected::show_B()
{
    std::cout << "/* ue_conn_state::ue_conn_connected::show_B() */" << std::endl;
}
#endif