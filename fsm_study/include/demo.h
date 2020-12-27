/*
 * @Author: your name
 * @Date: 2020-12-05 06:18:29
 * @LastEditTime: 2020-12-23 06:37:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /code/study_project/fsm_study/include/demo.h
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
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

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {

        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            i = s.find_first_of(s, i);
            j = s.find_last_of(s, j);

            std::swap(s[i++], s[j--]);
        }
        return s;
    }
    inline bool isVowel(char s)
    {
        return (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U');
    }
    string restoreString(string s, vector<int> &indices)
    {
        string result;
        map<int, char *> data;
        int length = indices.size();
        for (int i = 0; i < length; i++)
        {
            data.insert(pair<int, char *>(indices.at(i), &s[i]));
        }
        for (auto data_per : data)
        {

            result += *(data_per.second);
            // result.append(*(data_per.second));
        }
        return result;
    }
};