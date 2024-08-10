/*
寻找林克的回忆(1)
描述

image.png (./5651a11e2c.png)

为了找到百年沉睡的原因，寻回百年前与公主一起的记忆碎片，明白自己是谁，林克必须破解数独谜题。

林克需要在限定时间内，把9×9的数独补充完整，使得图中每行、每列、每个3 × 3的九宫格内数字1~9均恰好出现一次。

林克需要寻回失去的记忆碎片，你，作为林克的朋友，需要帮忙林克寻回9×9棋盘中失去的数字。

或许有一天，林克也能帮助你，寻回关于你是谁，你从哪里来的记忆碎片。

这是数独试炼I（解密成功可以解锁林克前25%的记忆碎片）

Image: (./2982_1.jpg)



输入
输入为9×9的数据。一共9行，每行有9个数字。

数字为0表示对应的数字盘为空。


输出
对于每个测试用例，程序应以与输入数据相同的格式打印解决方案(9×9)。

空单元格必须根据规则进行填充。

如果解决方案不是唯一的，则程序可以打印其中任何一种。


输入样例 1

103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
输出样例 1

143628579
572139468
986754231
391542786
468917352
725863914
237481695
619275843
854396127
提示

Andy(2021) (https://www.bilibili.com/video/BV1mU4y1b7WE/)

Andy(2020) (https://www.bilibili.com/video/BV1oC4y1s7sF)

改编自：POJ2676

《算法竞赛进阶指南》
*/

#include <iostream>

#define N 9
#define M 3

using namespace std;

inline bool Check_row(const short A[],bool Check[])
{
    for(const short *p=A; p-A<N; ++p)
        if(*p)
        {
            if(Check[*p-1])
                return false;
            else
                Check[*p-1]=true;
        }
    return true;
}

inline bool Check_col(const short A[][N],const short i,bool Check[])
{
    for(const short *p=*A+i; p-*A<N*N; p+=N)
        if(*p)
        {
            if(Check[*p-1])
                return false;
            else
                Check[*p-1]=true;
        }
    return true;
}

inline bool Check_cel(const short A[][N],const short i,const short j,bool Check[])
{
    const short *org_ptr=A[j*M];
    for(const short *p=org_ptr+i*M; p-org_ptr-i*M<M; ++p)
        for(const short *q=p; q-p<M*N; q+=N)
            if(*q)
            {
                if(Check[*q-1])
                    return false;
                else
                    Check[*q-1]=true;
            }
    return true;
}

inline bool Merge_checks(bool dest[],bool src[])
{
    for(bool *p=dest,*q=src; (p-dest<N)&&(q-src<N); ++p,++q)
    {
        if(*q)
            *p=true;
        *q=false;
    }
    return true;
}

inline bool detSol(const short Sol[][N])
{
    bool Check[N]= {false};
    for(const short (*p_1)[N]=Sol; p_1-Sol<N; ++p_1)
        if(Check_row(*p_1,Check))
            for(bool *p=Check; p-Check<N; ++p)
                *p=false;
        else
            return false;
    for(short i=0; i<N; ++i)
        if(Check_col(Sol,i,Check))
            for(bool *ptr=Check; ptr-Check<N; ++ptr)
                *ptr=false;
        else
            return false;
    for(short i=0; i<N/M; ++i)
        for(short j=0; j<N/M; ++j)
            if(Check_cel(Sol,i,j,Check))
                for(bool *ptr=Check; ptr-Check<N; ++ptr)
                    *ptr=false;
            else
                return false;
    return true;
}

bool Solve(short A[][N])
{
    for(short (*p)[N]=A; p-A<N; ++p)
        for(short *q=*p; q-*p<N; ++q)
            if(!(*q))
            {
                bool Check[N]= {false},Tmp[N]= {false};
                Check_row(*p,Check),Check_col(A,(short)(q-*p),Tmp),Merge_checks(Check,Tmp),Check_cel(A,(short)((q-*p)/M),(short)((p-A)/M),Tmp),Merge_checks(Check,Tmp);
                for(bool *ptr=Check; ptr-Check<N; ++ptr)
                    if(!(*ptr))
                    {
                        *q=(short)(ptr-Check+1);
                        if(Solve(A))
                            return true;
                        else
                            *q=0;
                    }
                return false;
            }
    return detSol(A);
}

int main()
{
    short A[N][N]= {0};
    for(short (*p_1)[N]=A; p_1-A<N; ++p_1)
    {
        for(short *q_1=*p_1; q_1-*p_1<N; ++q_1)
            *q_1=(short)(cin.get()-'0');
        cin.get();
    }
    if(Solve(A))
        for(short (*p_1)[N]=A; p_1-A<N; ++p_1)
        {
            for(short *q_1=*p_1; q_1-*p_1<N; ++q_1)
                cout<<*q_1;
            cout<<endl;
        }
    else
        cout<<"No Solution"<<endl;
    return 0;
}
