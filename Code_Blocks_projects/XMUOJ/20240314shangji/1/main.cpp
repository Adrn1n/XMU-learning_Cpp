/*
今年是2020年的第几天
描述

输入一个日期，用三个整数分别表示年、月、日。这三个整数都是合法的日期表示，且在公历2020年之内。计算出输入的日期是2020年的第几天。


输入
输入三个整数，分别表示年月日。


输出
输出一个整数，表示是2020年的第几天。


输入样例 1

2020 1 1
2020 7 11
2020 12 31
输出样例 1

1
193
366
*/

#include <iostream>

using namespace std;

const short DinM[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    short Y=0,M=0,D=0;
    while(cin>>Y>>M>>D)
    {
        for(const short *p=DinM+M-2; p-DinM>=0; p--)
            D+=*p;
        if((((!(Y%4))&&(Y%100))||(Y%400))&&(M>2))
            D++;
        cout<<D<<endl;
    }
    return 0;
}
