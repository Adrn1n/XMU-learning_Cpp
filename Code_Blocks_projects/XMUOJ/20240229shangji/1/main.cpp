/*
斐波那契和
描述

定义一个数列：f(0)=a,f(1)=b,f(n)=f(n−1)+f(n−2)
f(0)=a,f(1)=b,f(n)=f(n−1)+f(n−2)
其中a,b,n 为整数且n≥2
给出整数l,r ，请计算∑(f(i))_(i=l)^(r)
由于答案可能很大，你只需要输出答案的最后三位数(不含前导零)


输入
输入第一行为一个整数t(1≤t≤100)，代表一共有t 组输入

之后的t 行，每行四个用空格隔开的整数a,b,l,r(0≤a,b≤10^5 ,0≤l≤r≤1000)，含义如题目所述


输出
输出t 行 ，分别为每组输入的计算结果，只保留最后三位数字(不含前导零)


输入样例 1

4
1 1 0 3
1 1 5 5
1 1 10 50
0 1000 0 1
输出样例 1

7
8
29
0
提示

样例中第三组输入1 1 10 50的计算结果为
53316291029，取最后三位数为029，输出29
样例中第四组输入0 1000 0 1的计算结果为1000，取最后三位数为000，输出0

*/

#include <iostream>

#define L 1000

using namespace std;

int main()
{
    short t=0;
    cin>>t;
    while(t--)
    {
        short l=0,r=0,R=0;
        int a=0,b=0;
        cin>>a>>b>>l>>r;
        short A[r+2];
        A[0]=(short)(a%L),A[1]=(short)(b%L);
        for(short *p=A; p-A<r-1;)
            R=*p++,R+=*p++,*p--=R%L;
        R=0;
        for(short *p=A+l; p-A<=r;)
            R+=*p++,R%=L;
        cout<<R<<endl;
    }
    return 0;
}