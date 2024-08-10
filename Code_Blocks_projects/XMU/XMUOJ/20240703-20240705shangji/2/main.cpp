/*
二进制中1的最低位位置(打表+Lowbit)
描述

lowbit.jpg (./dcbaca3e1e.jpg)

打表法是寻找回忆不可或缺的重要方法，如果配合上lowbit，那么更难的问题也能迎刃而解。

请运用打表法和lowbit算法解决如下问题：

给定一个16位的十进制数，请把该数转换为二进制数来看待。

请找到该数看为二进制后，其最低位的1出现的位置。

也就是这个数最低位的1是二进制中的第几位呢？


输入
以1开头的二进制数的十进制表示B.

例如输入9.

image.png (./22827db03d.png)


输出
输出K，表示B中的1在第K位（K=0,1,2....15)

9的最低位的1出现在位置0.


输入样例 1

9
输出样例 1

0
输入样例 2

8
输出样例 2

3
提示

Andy讲解 (https://www.bilibili.com/video/BV1dC4y1s7LW)

8 = 2^3 故需要计算以2为底的log(2^3)=3，得到第3位。也就是8的二进制表示中，1出现在第3位。

用打表法计算Log2。

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4309_test_cases.zip)


*/

#include <iostream>

#define N 17

using namespace std;

inline int lowbit(const int a)
{
    return a&(-a);
}

inline int *Mk_pow_a_tab(int Res[],const short n,const short a)
{
    *Res=1;
    for(int *p=Res+1; p-Res<n; ++p)
        *p=*(p-1)*a;
    return Res;
}

inline short First_1_idx(int a)
{
    a=lowbit(a);
    int Pow_2[N]= {0};
    Mk_pow_a_tab(Pow_2,N,2);
    for(int *p=Pow_2; p-Pow_2<N; ++p)
        if(*p==a)
            return (short)(p-Pow_2);
    return -1;
}

int main()
{
    int B=0;
    cin>>B;
    cout<<First_1_idx(B)<<endl;
    return 0;
}
