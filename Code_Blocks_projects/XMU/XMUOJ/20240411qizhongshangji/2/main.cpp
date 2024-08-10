/*
红豆
描述

这可不是一般的红豆，这是王维诗里的红豆！
王初桐参加乡试屡次不中，正所谓淋过雨的人才会给别人撑伞。于是他决定出一道送分题给大家：

现在每个秀才都有一些红豆数量。a[i]表示第i个秀才的红豆数量。现在进行一些赠送操作。大家会互相赠送自己的红豆，完成所有操作后，求拥有最多数量红豆的秀才和拥有最少数量的秀才，他们拥有的红豆数量之差的绝对值。


输入
输入的第一行为一个整数 n（1≤n≤100），代表有 n 个秀才。

接下来的一行为 n 个正整数 a_i（1≤a_i ≤100），代表每个秀才拥有的红豆数量。

输入的第三行为一个整数 m（1≤m≤100），代表有 m 次赠送操作。

接下来 m 行，每行两个正整数 x,y。代表这次操作第 x 个秀才，将自己一半的红豆（需要向下取整）赠送给了第 y 个秀才。


输出
输出一行，代表拥有最多数量红豆的秀才和拥有最少数量的秀才，他们拥有的红豆数量之差的绝对值。


输入样例 1

3
3 1 2
3
0 2
2 1
2 0
输出样例 1

2
提示

第 1 次操作，秀才0将一半的红豆赠送给秀才2，a = [2,1,3]第 2 次操作，秀才2将一半的红豆赠送给秀才1，a = [2,2,2]第 3 次操作，秀才2将一半的红豆赠送给勇者0，a = [3,2,1]，输出 3 - 1 = 2 。
*/

#include <iostream>

using namespace std;

int main()
{
    short n=0,m=0;
    cin>>n;
    short A[n];
    for(short *p=A; p-A<n; p++)
        cin>>*p;
    cin>>m;
    short B[m][2];
    for(short (*p)[2]=B; p-B<m; p++)
    {
//        cin>>*(*p)>>*(*p+1);
//        A[*(*p+1)]+=(A[*(*p)]/2);
//        A[*(*p)]-=(A[*(*p)]/2);
        cin>>p[0][0]>>p[0][1];
        A[p[0][1]]+=(A[p[0][0]]/2);
        A[p[0][0]]-=(A[p[0][0]]/2);
    }
    short MAX=A[0],MIN=A[0];
    for(short *p=A; p-A<n; p++)
    {
        if(*p>MAX)
            MAX=*p;
        if(*p<MIN)
            MIN=*p;
    }
    cout<<MAX-MIN<<endl;
    return 0;
}