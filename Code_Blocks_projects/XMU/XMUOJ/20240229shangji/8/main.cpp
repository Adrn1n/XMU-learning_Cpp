/*
混合比较Ex (Nerfed)
描述

给出若干互不相等的十进制、八进制、十六进制、二进制整数，请将它们排序并从小到大输出

注意输出时不需要保留整数在输入中的进制，只需要按正常十进制格式输出

其中不同进制给出的格式如下：

十进制数：不包含前缀，例如1919，810

八进制数：前缀为单个0，例如0114，0514

十六进制数：前缀为0x，字母为小写英文字母，例如0x1f1e33，0x66ccff

二进制数：前缀为0b， 例如0b10，0b101010101

所有整数的数值部分均不包含前导零（即不会有0x00d或0001这种输入的出现）


输入
输入为一行字符串，包含若干按题目描述格式给出的整数a(1≤a≤10^8 )
整数间以逗号隔开，保证整数互不相等，整数个数n 满足1≤n≤100

输出
输出一行，将输入的整数排序并从小到大输出，各个数间以逗号隔开

不需要保留整数在输入中的进制，只需要按正常十进制格式输出


输入样例 1

0b11,0b101,0x1,0x2,6,04,0b1001,0b1000,0x7,0xa
输出样例 1

1,2,3,4,5,6,7,8,9,10
提示

如果你遇到了任何不会的知识点，请务必活用搜索引擎

对于排序操作，在本题你可以使用简单的选择排序、冒泡排序，或者使用stdlib.h中的qsort函数
*/

#include <iostream>

#define n_s_max 3000
#define n_n_max 100

using namespace std;

int manipulate(const char *S,int N[],const char Hex_alpha_to_num[])
{
    int n=0,*p_N=N;
    char flag=0;
    for(const char *p=S; *p; p++)
    {
        const char *p_stop=p;
        while((*p!=',')&&(*p))
        {
            if(!flag)
            {
                if((*p>'0')&&(*p<='9'))
                    flag=10;
                else if((*p=='0')&&(*(p+1)=='x'))
                    flag=16,p++,p_stop=p;
                else if((*p=='0')&&(*(p+1)=='b'))
                    flag=2,p++,p_stop=p;
                else
                    flag=8;
            }
            p++;
        }
        if(p==(p_stop+1))
        {
            if((flag==10)||(flag==8))
                *p_N++=*(p-1)-'0',flag=0,n++;
        }
        else
        {
            const char *q=p;
            int pow=1;
            for(q--; q>p_stop; pow*=flag,q--)
            {
                char i=(char)(*q-'0');
                if((i>=0)&&(i<=9))
                    *p_N+=i*pow;
                else
                    *p_N+=Hex_alpha_to_num[i+'0'-'a']*pow;
            }
            if(flag==10)
                *p_N+=(*q-'0')*pow;
            p_N++,flag=0,n++;
        }
    }
    return n;
}

int main()
{
    char A[n_s_max+1]= {0},Hex_alpha_to_num[6]= {10,11,12,13,14,15};
    cin>>A;
    int N[n_n_max]= {0};
    int n=manipulate(A,N,Hex_alpha_to_num);
    for(int *p=N; p-N<n-1; p++)
        for(int *q=p+1; q-N<n; q++)
            if(*p>*q)
                *p+=*q,*q=*p-*q,*p-=*q;
    for(int *p=N; p-N<n-1; p++)
        cout<<*p<<',';
    cout<<N[n-1]<<endl;
    return 0;
}
