/*
密码破译
描述

移位密码是古典密码学中最早，最简单的一种加、解密码方法，最早可追溯至古罗马时代，尤利乌斯·恺撒曾经使用过此密码。

移位密码通过将明文中所使用的字母按照一定的字数进行“平移”来加密，例如将所有字母全部向后平移两位后，A 变为 C，Z 变为 B

在这里，我们修改移位密码的规则，使每个字母移动的距离可能互不相同

修改后的加密规则将以一条字符串给出，其中字符串的第 i 个字符代表26个英文字母中的第 i 个字母经过加密变成的字母

给出修改后的加密规则，以及加密后的文本，请求出加密前的文本


输入
输入包含两行

第一行包含一个长度为 26，由大写英文字母组成的字符串 c 表示加密规则

其中 c_i(0≤i<26) 表示 A ~ Z 中第 i+1 个字母经过移动后变成的新字母（保证对于任意 /(i)=j，/(c_i)=c_j）

第二行中包含若干由空格隔开的、大写英文字母组成的字符串 s (1≤∣s∣≤100,0≤∑∣s∣≤10^4 )，表示加密后的文本


输出
输出一行，代表加密前的文本，各个字符串间由一个空格隔开


输入样例 1

BCDEFGHIJKLMNOPQRSTUVWXYZA
D ABCDEFG        HELLO WORLD
输出样例 1

C ZABCDEF GDKKN VNQKC
提示

不保证输入中空格的数量，即输入第二行总长度不确定
*/

#include <iostream>

#define L_Alpha 26
#define N 100

using namespace std;

//char MkDic(char *dest,const char *src)
//{
//    char ch='A';
//    while(ch<='Z')
//    {
//        for(const char *q=src;; q++)
//            if(*q==ch)
//            {
//                *dest=(char)((q-src)+'A');
//                break;
//            }
//        dest++,ch++;
//    }
//    return ch;
//}

int main()
{
//    char D[L_Alpha]= {0},d[L_Alpha+1]= {0};
    char C[L_Alpha+1]= {0},ch=0;
    for(char i=0; i<L_Alpha; i++)
    {
        cin>>ch;
        C[ch-'A']=(char)(i+'A');
    }
//    MkDic(d,D);
//    while((cin.get()!=EOF))
    while((cin.get())!=EOF)
    {
        char S[N+1]= {0};
        cin>>S;
        for(char *p=S; *p; p++)
            *p=C[*p-'A'];
//            *p=d[*p-'A'];
        cout<<S<<' ';
    }
    cout<<endl;
    return 0;
}
