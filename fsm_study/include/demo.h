/*
 * @Author: your name
 * @Date: 2020-12-05 06:18:29
 * @LastEditTime: 2020-12-12 00:41:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /code/study_project/fsm_study/include/demo.h
 */
#include <iostream>
class ue_conn_state
{
public:
    class ue_conn_unit_state
    {
    public:
        virtual void show_A()
        {
            std::cout << "ue_conn_unit_state show_A" << std::endl;
        };
        virtual void show_B()
        {
            std::cout << "ue_conn_unit_state show_B" << std::endl;
        };
    };
    friend ue_conn_unit_state;
    class ue_conn_idle : public ue_conn_unit_state
    {
    public:
        void show_A();
        void show_C();
    };
    friend ue_conn_idle;
    class ue_conn_connected : public ue_conn_unit_state
    {
    public:
        void show_B();
        void show_C();
    };
    friend class ue_conn_connected;
    ue_conn_unit_state *get_current_state()
    {
        return current_state;
    }
    ue_conn_unit_state *get_current_state_2()
    {
        return current_state;
    }
    ue_conn_state()
    {
        current_state = &ue_conn_idle_A;
    }
    void next_state(ue_conn_unit_state &ue_conn_unit_state)
    {
        current_state = &ue_conn_unit_state;
    }

private:
    ue_conn_unit_state *current_state;
    ue_conn_idle ue_conn_idle_A;
    ue_conn_connected ue_conn_connected;
};