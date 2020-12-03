/*
 * @Author: your name
 * @Date: 2020-12-03 00:30:20
 * @LastEditTime: 2020-12-03 01:31:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/fsm_study/main.cpp
 */
#include "test.h"
int main(int argc, char const *argv[])
{

    ue_conn_state *state = new ue_conn_state();
    ue_conn_idle *ue_conn_idle = state->get_current_state();
    ue_conn_idle->show_A();
    // state->get_current_state()->show_A();

    std::cout << "/* message */" << std::endl;
    return 0;
}
