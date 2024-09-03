/*
五子棋裁判
描述

在程序设计实践课上，老师给大家布置下了这样的实验任务：编写一个五子棋应用程序

胜负判定是五子棋程序最核心的部分。给出当前棋盘的状态，请你完成对五子棋胜负的判定（仅考虑当前状态，不考虑后续落子）

规则：在水平、垂直或对角线方向形成5个以上棋子连续的一方获胜


输入
输入第一行为一个整数 t (1≤t≤100)，代表一共有 t 组输入

对于每组输入：

第一行一个整数 n (1≤n≤20)，代表棋盘的大小为 n× n
之后的 n 行，每行包含一个长度为 n 的字符串，代表当前棋盘的状态，其中空位用字符.表示，黑棋、白棋分别用字符BW表示

输入保证只会出现胜负未定、黑棋胜利、白棋胜利三种情况（即最多只会有一方有5连子）


输出
输出 t 行 ，分别为每组输入的胜负结果

若黑棋胜利输出"Black"， 若白棋胜利输出"White"，若胜负未定则输出"Not so fast"（均不包含引号)


输入样例 1

3
5
WWWWW
BBBB.
.....
.....
.....
5
B...W
.B.W.
..B..
.W.B.
W...B
5
.....
.....
.....
.....
.....
输出样例 1

White
Black
Not so fast
*/

#include <iostream>

#define cont_num 5

using namespace std;

bool is_ch(const char *p,const char ch,int *cnt)
{
    if(*p==ch)
    {
        (*cnt)++;
        return true;
    }
    else
    {
        *cnt=0;
        return false;
    }
}

bool Judge(const char *S,const int n,const char ch,const int cont_n)
{
    int cnt=0;
    for(const char *p=S; p-S<n*(n+1); p+=(n+1))
    {
        cnt=0;
        for(const char *q=p; q-p<n; q++)
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
        }
    }
    for(const char *p=S; p-S<n; p++)
    {
        cnt=0;
        for(const char *q=p; q-p<n*(n+1); q+=(n+1))
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
        }
    }
    for(const char *p=S; p-S<n; p++)
    {
        cnt=0;
        for(const char *q=p; q-p<n*(n+1); q+=n)
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
            if(!((q-S)%(n+1)))
                break;
        }
    }
    for(const char *p=S+2*n; p-S<3*n*n-1; p+=(n+1))
    {
        cnt=0;
        for(const char *q=p; q-S<n*(n+1); q+=n)
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
            if(!((q-S)%(n+1)))
                break;
        }
    }
    for(const char *p=S+n-1; p>=S; p--)
    {
        cnt=0;
        for(const char *q=p; q-p<n*(n+1); q+=n+2)
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
            if(!(q-S+2)%(n+1))
                break;
        }
    }
    for(const char *p=S+n+1; p-S<n*(n+1); p+=(n+1))
    {
        cnt=0;
        for(const char *q=p; q-S<n*(n+1); q+=n+2)
        {
            is_ch(q,ch,&cnt);
            if(cnt>=cont_n)
                return true;
            if(!(q-S+2)%(n+1))
                break;
        }
    }
    return false;
}

int main()
{
    short t=0;
    cin>>t;
    while(t--)
    {
        short n=0;
        cin>>n;
        char B[n+1][n+1];
        for(char *p=B[0]; p-B[0]<n*(n+1); p+=(n+1))
            cin>>p;
        if(Judge(B[0],n,'B',cont_num))
            cout<<"Black"<<endl;
        else if(Judge(B[0],n,'W',cont_num))
            cout<<"White"<<endl;
        else
            cout<<"Not so fast"<<endl;
    }
    return 0;
}
