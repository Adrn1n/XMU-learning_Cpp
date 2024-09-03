/*
放苹果
描述

image.png (./7b3bce6c56.png)

要寻找克罗克果实，林克需要把苹果放在盘子里，其中只有一种情况可以让克罗克果实出现。所以，林克需要尝试所有的放法。

有M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的放法？

注意：5，1，1和1，5，1 是同一种放法。


输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。0<=M，N<=10。


输出
对输入的每组数据M和N，用一行输出相应的K。K为正整数，代表共有几种放法。


输入样例 1

1
7 3
输出样例 1

8
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1y64y1D7AM)

改编自《分苹果》

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4253_test_cases.zip)


*/

#include <iostream>

using namespace std;

long long Search(const short m,const short n,const short Min)
{
    long long res=0;
    if(n>1)
        for(short i=Min; (m-i)/(n-1)>=i; ++i)
            res+=Search(m-i,n-1,i);
    else if((n==1)||((!m)&&(!n)))
        return 1;
    return res;
}

int main()
{
    short t=0;
    cin>>t;
    while(t--)
    {
        short M=0,N=0;
        cin>>M>>N;
        cout<<Search(M,N,0)<<endl;
    }
    return 0;
}
