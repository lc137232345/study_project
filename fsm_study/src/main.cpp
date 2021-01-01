/*
 * @Author: your name
 * @Date: 2020-12-05 06:34:10
 * @LastEditTime: 2020-12-29 04:30:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /code/study_project/fsm_study/src/main.cpp
 */
#include <iostream>
#include "demo.h"
#include <array>
void test(const int &a)
{
    std::cout << a << std::endl;
    //a = 11;
}
using namespace std;
int main(int argc, char const *argv[])
{
#if 0
    ue_conn_state *ue_conn_stat = new ue_conn_state;

    const double pi = 3.14;
    const int a = 10;
    test(a);
    std::cout << a << std::endl;
    const double *cptr = &pi;
    double dval = 12.5;
    cptr = &dval;
    ue_conn_stat->get_current_state()->show_A();
    std::cout
        << "/* message */" << std::endl;

    Solution *solution = new Solution();
    std::string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    // solution->reverseVowels(s);
    // solution->restoreString(s, indices);
    std::cout << solution->restoreString(s, indices) << std::endl;
    delete solution;
#endif
    std::size_t idx;
    array<char, 6> as = {'1', '2', '3', '4', '5', '6'};
    std::cout << as.data() << std::endl;
    for (auto &a : as)
    {
        a = '0';
    }
    for (auto a : as)
    {
        std::cout << a << std::endl;
    }

    return 0;
}
