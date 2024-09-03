/*
汉诺塔I
描述

image.png (./c9f1809151.png)

有三根杆子A，B，C。A杆上有N个(N>1)穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至C杆： 每次只能移动一个圆盘； 大盘不能叠在小盘上面。 提示：可将圆盘临时置于B杆，也可将从A杆移出的圆盘重新移回A杆，但都必须遵循上述两条规则。

问：如何移？最少要移动多少次？



解法

解法的基本思想是递归。假设有A、B、C三个塔，A塔有N块盘，目标是把这些盘全部移到C塔。那么先把A塔顶部的N-1块盘移动到B塔，再把A塔剩下的大盘移到C，最后把B塔的N-1块盘移到C。 每次移动多于一块盘时，则再次使用上述算法来移动。


输入
盘子个数n(1<=n<=20)


输出
输出移动的步骤，每行一步，如从A座移动到C座，输出"A->C"。


输入样例 1

3
输出样例 1

A->C
A->B
C->B
A->C
B->A
B->C
A->C
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1qy4y187N1)
*/

#include <iostream>

using namespace std;

bool Solve(short n,char src,char dest,char tmp)
{
    if(n>1)
    {
        Solve(--n,src,tmp,dest);
        cout<<src<<"->"<<dest<<endl;
        Solve(n,tmp,dest,src);
    }
    else if(n==1)
    {
        cout<<src<<"->"<<dest<<endl;
//        return true;
    }
    else
        return false;
    return true;
}

int main()
{
    short n=0;
    cin>>n;
    Solve(n,'A','C','B');
    return 0;
}
