/*
寻找林克的回忆(3)
描述

See the source image (./th (1).jpg)

为了寻回百年前与公主一起的记忆碎片，林克历尽千辛万苦总算破解了数独试炼I和II的谜题，寻回50%的记忆碎片。

如今，摆在他面前是数独试炼III——传说中的靶形数独（通过后可以获得剩下的30%的记忆碎片)。

靶形数独的方格同普通数独一样，在9×9的大九宫格中有9个3×3的小九宫格（用粗黑色线隔开的）。

在这个大九宫格中，有一些数字是已知的，根据这些数字，利用逻辑推理，在其他的空格上填入1到9的数字。

每个数字在每个小九宫格内不能重复出现，每个数字在每行、每列也不能重复出现。

但靶形数独有一点和普通数独不同，即每一个方格都有一个分值，而且如同一个靶子一样，离中心越近则分值越高（如下图所示）。

靶子.jpe.jpg (./19_1add32be19-靶子.jpe.jpg)

上图具体的分值分布是：

最里面一格（黄色区域）为10分
黄色区域外面的一圈（红色区域）每个格子为9分
再外面一圈（蓝色区域）每个格子为8分
蓝色区域外面一圈（棕色区域）每个格子为7分
最外面一圈（白色区域）每个格子为6 分

每个人必须完成一个给定的数独（每个给定数独可能有不同的填法），而且要争取更高的总分数。

而这个总分数即每个方格上的分值和完成这个数独时填在相应格上的数字的乘积的总和。

如图，在以下的这个已经填完数字的靶形数独游戏中，总分数为2829。

游戏规定，将以总分数的高低决出胜负。

靶子2.jpe.jpg (./19_55aa03a419-靶子2.jpe.jpg)

求对于给定的靶形数独，能够得到的最高分数。


输入
输入一共包含9行。

每行 9 个整数（每个数都在 0—9 的范围内），表示一个尚未填满的数独方格，未填的空格用“0”表示。

每两个数字之间用一个空格隔开。


输出
输出可以得到的靶形数独的最高分数。

如果这个数独无解，则输出整数-1。


输入样例 1

7 0 0 9 0 0 0 0 1
1 0 0 0 0 5 9 0 0
0 0 0 2 0 0 0 8 0
0 0 5 0 2 0 0 0 3
0 0 0 0 0 0 6 4 8
4 1 3 0 0 0 0 0 0
0 0 7 0 0 2 0 9 0
2 0 1 0 6 0 8 0 4
0 8 0 5 0 4 0 1 2
输出样例 1

2829
提示

Andy(2021) (https://www.bilibili.com/video/bv1Qb4y1D7hY)

Andy(2020) (https://www.bilibili.com/video/BV1mA411b7hB)

ACWing的讲解 (https://www.acwing.com/video/272/)
*/

#include <iostream>
#include <algorithm>

#define N 9
#define M 3
#define Num ((1<<N)-1)

using namespace std;

const short Weights[(N+1)/2]= {6,7,8,9,10};

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

inline short Here_score(const short x,const short y,const short val)
{
    short i=min(min(x,(short)(N-1-x)),min(y,(short)(N-1-y)));
    return (short)(val*Weights[i]);
}

inline short Ini(const short A[][N],short Row[],short Col[],short Cell[][N/M])
{
    short score=0;
    fill(Row,Row+N,Num),fill(Col,Col+N,Num),fill(*Cell,*Cell+(N/M)*(N/M),Num);
    for(const short (*p)[N]=A; p-A<N; ++p)
        for(const short *q=*p; q-*p<N; ++q)
            if(*q)
            {
                if(!Mod((short)(q-*p),(short)(p-A),*q,false,Row,Col,Cell))
                    return -1;
                else
                    score+=Here_score((short)(q-*p),(short)(p-A),*q);
            }
    return score;
}

inline short Avail(short row,short col,short cell)
{
    return (short)(row&col&cell);
}

short Solve(short A[][N],short Row[],short Col[],short Cell[][N/M])
{
    short x=0,y=0,n=10;
    bool flag=false;
    for(short i=0; i<N; ++i)
        for(short j=0; j<N; ++j)
            if(!A[i][j])
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
        short max_mark=0,tmp_mark;
        for(short avail=Avail(Row[y],Col[x],Cell[y/M][x/M]); avail; avail-=lowbit(avail))
        {
            auto val=(short)(First_1_idx_tab[avail-1]+1);
            if(Mod(x,y,val,false,Row,Col,Cell))
            {
                A[y][x]=val;
                if((tmp_mark=Solve(A,Row,Col,Cell))>=0)
                {
                    tmp_mark+=Here_score(x,y,val);
                    if(max_mark<tmp_mark)
                        max_mark=tmp_mark;
                    flag=false;
                }
                if(Mod(x,y,val,true,Row,Col,Cell))
                    A[y][x]=0;
                else
                    return -1;
            }
            else
                return -1;
        }
        if(flag)
            return -1;
        else
            return max_mark;
    }
    else
        return 0;
}

int main()
{
    short A[N][N]= {0};
    for(short *p=*A; p-*A<N*N; ++p)
        cin>>*p;
    Mk_n_avail_tab(N_avail_tab,Num);
    Mk_pow_a_tab(Pow_2_tab,N,2);
    Mk_first_1_idx_tab(First_1_idx_tab,Num,N,Pow_2_tab);
    short Row[N]= {0},Col[N]= {0},Cell[N/M][N/M]= {0},score,tmp;
    bool flag=true;
    if((score=Ini(A,Row,Col,Cell))>=0)
        if((tmp=Solve(A,Row,Col,Cell))>=0)
        {
            cout<<score+tmp<<endl;
            flag=false;
        }
    if(flag)
        cout<<-1<<endl;
    return 0;
}
