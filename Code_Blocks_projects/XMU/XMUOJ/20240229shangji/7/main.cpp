/*
混合比较
描述

给出若干个十进制数、八进制数、十六进制数，请你输出其中最大的一个数，并保留它在输入中的进制

当有多个数为最大时，请输出这些数中在输入中最早出现的一个


输入
输入共有四行

第一行三个用空格隔开的十进制整数x, y, z (1≤x,y,z≤100)，分别代表十进制数、八进制数、十六进制数的个数

第二行 x 个用空格隔开的十进制数

第三行 y 个用空格隔开的八进制数

第四行 z 个用空格隔开的十六进制数，其中字母为小写英文字母

对所有给出的整数 a，0≤a≤10^8


输出
输出一个整数代表最大值，保留这个数在输入时的进制

当有多个数为最大时，输出这些数中在输入中最早出现的一个


输入样例 1

2 1 1
123 456
24
34f
输出样例 1

34f
*/

#include <iostream>

#define Hex_L 7

using namespace std;

int OtoD(int O)
{
    int R=0;
    for(int pow=1; O; pow*=8)
        R+=(O%10)*pow,O/=10;
    return R;
}

int HtoD(const char *S,const short Hex_alpha_to_num[])
{
    const char *p=S;
    while(*p++);
    p--;
    int R=0;
    for(int pow=1; (--p)-S>=0; pow*=16)
    {
        short a=*p-'0';
        if((a>=0)&&(a<=9))
            R+=a*pow;
        else
            R+=Hex_alpha_to_num[a+'0'-'a']*pow;
    }
    return R;
}

int main()
{
    short Hex_alpha_to_num[6]= {10,11,12,13,14,15};
    short x=0,y=0,z=0,max_n=0;
    cin>>x>>y>>z;
    int R[x+y+z+1],O[y];
    char H[z][Hex_L+1];
    for(int *p=R; p-R<x; p++)
        cin>>*p;
    for(int *p=R+x,*q=O; p-R<x+y; p++,q++)
        cin>>*q,*p=OtoD(*q);
    for(int *p=R+x+y,i=0; p-R<x+y+z; p++,i++)
        cin>>H[i],*p=HtoD(H[i],Hex_alpha_to_num);
    for(int *p=R,MAX=*R; p-R<x+y+z; p++)
        if(*p>MAX)
            MAX=*p,max_n=p-R;
    if(max_n<x)
        cout<<R[max_n]<<endl;
    else if(max_n<x+y)
        cout<<O[max_n-x]<<endl;
    else
        cout<<H[max_n-x-y]<<endl;
    return 0;
}
