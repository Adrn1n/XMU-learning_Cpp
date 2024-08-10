/*
标识符
描述

在计算机高级语言中，用来对变量、符号变量名、函数、数组、类型等命名的有效字符序列统称为标识符 (identifier)

输入若干个标识符，请你依次判断这些标识符在C语言中是否合法

本题仅考虑标识符组成字符的限制，不考虑标识符和其他标识符、C语言关键字的重复


输入
输入第一行为一个整数 n (1≤n≤100)，代表标识符的数量

接下来的 n 行，每行一个由符号、英文字母、数字组成的字符串 s (1≤∣s∣≤100)，代表一个标识符


输出
输出 n 行，表示每个标识符的判断结果

如果标识符合法输出"Great"，如果不合法输出"Bad"（均不包含引号）


输入样例 1

5
hello_world
int
printf
*
hello_world
输出样例 1

Great
Great
Great
Bad
Great
提示

推荐使用scanf读入字符串
*/

#include <iostream>

#define N 100

using namespace std;

bool isAlpha(const char *p)
{
    if(((*p>='A')&&(*p<='Z'))||((*p>='a')&&(*p<='z')))
        return true;
    else
        return false;
}

int main()
{
    short n=0;
    cin>>n;
    while(n--)
    {
        char S[N+1]= {0};
        cin>>S;
        bool flag=true;
        if((isAlpha(S))||(*S=='_'))
        {
            for(char *p=S+1; *p; p++)
                if((!isAlpha(p))&&((*p<'0')||(*p>'9'))&&(*p!='_'))
                {
                    flag=false;
                    break;
                }
        }
        else
            flag=false;
        if(flag)
            cout<<"Great"<<endl;
        else
            cout<<"Bad"<<endl;
    }
    return 0;
}
