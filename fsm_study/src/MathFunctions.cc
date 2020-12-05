/*
 * @Author: your name
 * @Date: 2020-12-04 22:32:49
 * @LastEditTime: 2020-12-04 22:33:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/fsm_study/math/MathFunctions.cc
 */
double power(double base, int exponent)
{
    int result = base;
    int i;

    if (exponent == 0)
    {
        return 1;
    }

    for (i = 1; i < exponent; ++i)
    {
        result = result * base;
    }

    return result;
}