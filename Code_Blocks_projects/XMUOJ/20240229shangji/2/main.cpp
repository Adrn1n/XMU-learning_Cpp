/*
披萨
描述

某人有好多披萨，他想知道所有披萨的面积之和

每个披萨可以看作半径为 r， 圆心角为 α 度的扇形，请你求出所有披萨的面积之和


输入
输入第一行为一个整数 n (1≤n≤100) 表示披萨个数

接下来的 n 行，每行两个整数 r, α (1≤r≤100,1≤α≤360) ，代表每个披萨的半径和圆心角（单位为度）


输出
输出一行，代表所有披萨的面积和（以四舍五入的方式保留三位小数）


输入样例 1

2
1 360
2 180
输出样例 1

9.425
提示

本题对答案精度要求较高，请注意变量类型或计算方式对答案精度的影响

请尽量提高圆周率的精度！

圆周率的精确位数也会对答案造成影响（例如仅保留6位数下，经过乘法以及多次累加的扩大，误差足以进入三位小数），可以尝试用数学函数计算圆周率
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define Pi 2*asin(1)
#define full_ang 360

int main()
{
    short N=0;
    cin>>N;
    double R=0;
    for(short n=0; n<N; n++)
    {
        short r=0,a=0;
        cin>>r>>a;
        R+=(Pi*r*r*a/full_ang);
    }
    cout<<fixed<<setprecision(3)<<R<<endl;
    return 0;
}
