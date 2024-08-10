/*
三角形
描述

三角形需满足两边之和大于第三边。

假设有 N 根木棒，现在要挑选其中的三根，问能拼出的三角形的最大周长是多少?

如果不能拼成任何一个三角形，输出-1。


输入
先输入正整数N，表示木棒的个数，1≤N≤1000。再输入 N 个数，表示每一根木棒的长度。木棒的长度都是不超过100000的正整数。


输出
输出能拼出三角形的最大周长。如果不能拼成三角形，则输出-1。


输入样例 1

3 1 1 100
7 1 9 9 90 2 2 4
输出样例 1

-1
22
提示

木棍长度：(0,2^(31)−1)
*/

#include <iostream>

using namespace std;

int C_Max(int *A,short N)
{
    if(N>2)
    {
        for(int *p=A; p-A<N-1; p++)
            for(int *q=p+1; q-A<N; q++)
                if(*p<*q)
                    *p+=*q,*q=*p-*q,*p-=*q;
        for(int *a=A,*b=a+1,*c=b+1; c-A<N; a++,b++,c++)
            if((*b+*c)>*a)
                return *a+*b+*c;
    }
    return -1;
}

int main()
{
    short N=0;
    while(cin>>N)
    {
//        int A[N],C,C_max=0;
        int A[N];
        for(int *p=A; p-A<N; p++)
            cin>>*p;
//        if(N>2)
//            for(int *a=A; a-A<N-2; a++)
//                for(int *b=a+1; b-A<N-1; b++)
//                    for(int *c=b+1; c-A<N; c++)
//                        if((*a+*b>*c)&&(*b+*c>*a)&&(*c+*a>*b))
//                            C_max=((C=*a+*b+*c)>C_max)?C:C_max;
//        if(C_max)
//            cout<<C_max<<endl;
//        else
//            cout<<-1<<endl;
        cout<<C_Max(A,N)<<endl;
    }
    return 0;
}
