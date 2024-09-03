/*
寻找林克的回忆(2)
描述

image.png (./13e7012948.png)

为了找到百年沉睡的原因，寻回百年前与公主一起的记忆碎片，明白自己是谁，林克必须破解数独谜题：

林克需要在限定时间内，把9×9的数独补充完整，使得图中每行、每列、每个3 × 3的九宫格内数字1~9均恰好出现一次。

林克需要寻回失去的记忆碎片，你，作为林克的朋友，需要帮忙林克寻回9×9棋盘中失去的数字。

或许有一天，林克也能帮助你，寻回关于你是谁，你从哪里来的记忆碎片。

这是数独试炼II（解密成功可以解锁林克25%的记忆碎片）

请编写一个程序填写数独。

数独.png (./19_8cb8eda618-数独.png)


输入
输入包含多组测试用例。

每个测试用例占一行，包含81个字符，代表数独的81个格内数据（顺序总体由上到下，同行由左到右）。

每个字符都是一个数字（1-9）或一个”.”（表示尚未填充）。

您可以假设输入中的每个谜题都只有一个解决方案。

文件结尾处为包含单词“end”的单行，表示输入结束。


输出
每个测试用例，输出一行数据，代表填充完全后的数独。


输入样例 1

.2738..1..1...6735.......293.5692.8...........6.1745.364.......9518...7..8..6534.
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
输出样例 1

527389416819426735436751829375692184194538267268174593643217958951843672782965341
416837529982465371735129468571298643293746185864351297647913852359682714128574936
提示

Andy(2021) (https://www.bilibili.com/video/BV1uA411V7Nr/)

Andy(2020) (https://www.bilibili.com/video/BV1Ki4y1t7mf)

ACWing讲解 (https://www.acwing.com/problem/content/video/168/)

来源：2984 (http://bailian.openjudge.cn/practice/2984)
*/

#include <iostream>
#include <algorithm>

#define N 9
#define M 3
#define Num ((1<<N)-1)

using namespace std;

short Pow_2_tab[N]= {0},N_avail_tab[Num]= {0},First_1_idx_tab[Num]= {0};

inline short lowbit(const short a)
{
    return (short)(a&(-a));
}

inline short *Mk_n_avail_tab(short Res[],const short n)
{
    if(n>0)
    {
        for(short *p=Res; p-Res<n; ++p)
        {
            short a=(short)(p-Res),res=0,tmp;
            while((tmp=lowbit(a)))
            {
                a-=tmp;
                ++res;
            }
            *p=res;
        }
        return Res;
    }
    else
        return nullptr;
}

inline short *Mk_pow_a_tab(short Res[],const short n,const short a)
{
    if(n>0)
    {
        *Res=1;
        for(short *p=Res+1; p-Res<n; ++p)
            *p=(short)(*(p-1)*a);
        return Res;
    }
    else
        return nullptr;
}

inline short *Mk_first_1_idx_tab(short Res[],const short n,const short m,const short pow_2_tab[])
{
    if(n>0)
    {
        for(short *p=Res; p-Res<n; ++p)
        {
            bool flag=true;
            for(const short *q=pow_2_tab; q-pow_2_tab<m; ++q)
            {
                short a=lowbit((short)(p-Res+1));
                if(a==*q)
                    *p=(short)(q-pow_2_tab),flag=false;
            }
            if(flag)
                return nullptr;
        }
        return Res;
    }
    else
        return nullptr;
}

inline bool Check_bit(const short a,const short val,const bool isClear)
{
    if(a&val)
    {
        if(isClear)
            return false;
        else
            return true;
    }
    else if(isClear)
        return true;
    else
        return false;
}

inline bool Mod(const short x,const short y,short val,const bool isClear,short Row[],short Col[],short Cell[][N/M])
{
    val=(short)(1<<(val-1));
    if(!Check_bit(Row[y],val,isClear))
        return false;
    if(!Check_bit(Col[x],val,isClear))
        return false;
    if(!Check_bit(Cell[y/M][x/M],val,isClear))
        return false;
    if(isClear)
        val=(short)(-val);
    Row[y]-=val,Col[x]-=val,Cell[y/M][x/M]-=val;
    return true;
}

inline bool Ini(const string &S,short Row[],short Col[],short Cell[][N/M])
{
    fill(Row,Row+N,Num),fill(Col,Col+N,Num),fill(*Cell,*Cell+(N/M)*(N/M),Num);
    for(auto it_1=S.begin(); it_1<S.end(); it_1+=N)
        for(auto it_2=it_1; it_2-it_1<N; ++it_2)
            if(*it_2!='.')
                if(!Mod((short)(it_2-it_1),(short)((it_1-S.begin())/N),(short)(*it_2-'0'),false,Row,Col,Cell))
                    return false;
    return true;
}

inline short Avail(short row,short col,short cell)
{
    return (short)(row&col&cell);
}

bool Solve(string &S,short Row[],short Col[],short Cell[][N/M])
{
    short x=0,y=0,n=10;
    bool flag=false;
    for(short i=0; i<N; ++i)
        for(short j=0; j<N; ++j)
            if(S[i*N+j]=='.')
            {
                short a=Avail(Row[i],Col[j],Cell[i/M][j/M]);
                if(N_avail_tab[a]<n)
                {
                    n=N_avail_tab[a];
                    x=j,y=i;
                }
                flag=true;
            }
    if(flag)
    {
        for(short avail=Avail(Row[y],Col[x],Cell[y/M][x/M]); avail; avail-=lowbit(avail))
        {
            auto val=(short)(First_1_idx_tab[avail-1]+1);
            if(Mod(x,y,val,false,Row,Col,Cell))
            {
                S[y*N+x]=(char)(val+'0');
                if(Solve(S,Row,Col,Cell))
                    return true;
                else
                {
                    S[y*N+x]='.';
                    if(!Mod(x,y,val,true,Row,Col,Cell))
                        return false;
                }
            }
            else
                return false;
        }
        return false;
    }
    else
        return true;
}

int main()
{
    Mk_n_avail_tab(N_avail_tab,Num);
    Mk_pow_a_tab(Pow_2_tab,N,2);
    Mk_first_1_idx_tab(First_1_idx_tab,Num,N,Pow_2_tab);
    string S;
    while(cin>>S,S!="end")
    {
        short Row[N]= {0},Col[N]= {0},Cell[N/M][N/M]= {0};
        if(Ini(S,Row,Col,Cell))
        {
            if(Solve(S,Row,Col,Cell))
                cout<<S<<endl;
            else
                cout<<"No solution"<<endl;
        }
        else
            cout<<"Error"<<endl;
    }
    return 0;
}
