/*
 * @Author: your name
 * @Date: 2020-12-03 00:18:18
 * @LastEditTime: 2020-12-03 01:15:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/fsm_study/test.h
 */
#include <iostream>

class ue_conn_idle
{
public:
    void show_A();
};

class ue_conn_state
{

public:
    ue_conn_idle *get_current_state()
    {
        return current_state;
    }

private:
    ue_conn_idle *current_state;
};
