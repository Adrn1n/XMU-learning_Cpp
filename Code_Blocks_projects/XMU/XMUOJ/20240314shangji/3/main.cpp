/*
统计字符的出现次数
描述

输入字符串，字符串由英文字母、数字、标点符号和运算符号组成 (不含空格)。

统计每个字符在该字符串中出现次数，按出现次数从大到小的顺序，将字符和其出现次数输出。

如果存在出现次数相等的字符，ASCII码值较大的字符排在前面。


输入
输入一个字符串（ASCII范围：[33, 126]），字符串长度最多为1000。


输出
按字符出现次数的排序，输出字符和其出现次数，两者之间用冒号隔开。


输入样例 1

HelloWorld!
XMU:(1+2)*9=27
输出样例 1

l:3 o:2 r:1 e:1 d:1 W:1 H:1 !:1
2:2 X:1 U:1 M:1 =:1 ::1 9:1 7:1 1:1 +:1 *:1 ):1 (:1
提示

输出的末尾有空格。
*/

#include <iostream>

using namespace std;

#define L 1000
#define N 94

typedef struct
{
    char c;
    short cnt;
} char_cnt;

int main()
{
    char S[L+1]= {0};
    while(cin>>S)
    {
        char_cnt A[N+1]= {0};
        for(char_cnt *p=A; p-A<N; p++)
            p->c=(char)(126-(p-A));
        for(char *p=S; *p; p++)
            A[126-*p].cnt++;
        for(char_cnt *p=A; p-A<N-1; p++)
            for(char_cnt *q=p+1; q-A<N; q++)
                if(((p->cnt)<(q->cnt))||(((p->cnt)==(q->cnt))&&((p->c)<(q->c))))
                {
                    char_cnt tmp=*p;
                    *p=*q,*q=tmp;
                }
        for(char_cnt *p=A; p->cnt; p++)
            cout<<p->c<<':'<<p->cnt<<' ';
        cout<<endl;
    }
    return 0;
}
