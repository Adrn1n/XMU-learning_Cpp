/*
矩阵扩展
描述

通过本课程的学习，我们对矩阵越来越熟悉。

给定一个m×n的矩阵，拷贝矩阵最外围一层元素，将原矩阵扩展为一个新的矩阵，如下图所示。扩展后的矩阵大小为(m+2)×(n+2)。

1679137883850.jpg  //(./f491defeec.jpg)


输入
每次输入有m+1行。

第一行为两个整数(3≤m+2≤30) ，n (3≤n+2≤30) ，分别代表矩阵的行和列。

之后的 m 行，每行有n 个由空格隔开的整数，每个整数的取值范围为 [-10000, 10000]。


输出
每次输出有m+2行，n+2 列整数。


输入样例 1

3 4
1 2 3 4
5 6 7 8
9 10 11 12
输出样例 1

1 1 2 3 4 4
1 1 2 3 4 4
5 5 6 7 8 8
9 9 10 11 12 12
9 9 10 11 12 12
提示

输出的每一行末尾没有空格。
*/

#include <iostream>

using namespace std;

short* Batch_Copy(short *desk,short *src,short n,short d)
{
    short *p=desk,*q=src;
    for(short i=0; i<n; i++,p+=d,q+=d)
        *p=*q;
    return desk;
}

int main()
{
    short m=0,n=0;
    while(cin>>m>>n)
    {
        short A[m+2][n+2];
        for(short *p=&A[1][1]; p-&A[m][1]<=0; p+=(n+2))
            for(short *q=p; q-p<n; q++)
                cin>>*q;
        A[0][0]=A[1][1],A[0][n+1]=A[1][n],A[m+1][0]=A[m][1],A[m+1][n+1]=A[m][n];
        Batch_Copy(&A[0][1],&A[1][1],n,1),Batch_Copy(&A[m+1][1],&A[m][1],n,1),Batch_Copy(&A[1][0],&A[1][1],m,n+2),Batch_Copy(&A[1][n+1],&A[1][n],m,n+2);
//        for(short *p=A[0]; p-&A[m+1][0]<=0; p+=(n+2))
        for(short (*p)[n+2]=A; p-A<=m+1; p++)
        {
//            for(short *q=p; q-p<n+2; q++)
            for(short *q=*p; q-*p<n+2; q++)
//                if(q-p==n+1)
                if(q-*p==n+1)
                    cout<<*q;
                else
                    cout<<*q<<' ';
            cout<<endl;
        }
    }
    return 0;
}
