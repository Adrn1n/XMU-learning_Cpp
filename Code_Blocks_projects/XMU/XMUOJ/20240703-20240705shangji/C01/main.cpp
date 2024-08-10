/*
真假记忆碎片
描述

Image: (./v2-2b8f66b224724de6cfea455f22d5f3c1_720w.jpg)


在千辛万苦得到一个记忆碎片之后，林克需要辨别真假，若是所得到的并不是发生历史中的碎片，乃是后人捏着的，那么林克如何寻回完整的自己呢？

已知林克找到的记忆碎片9×9矩阵是初始矩阵A的解法，也就是记忆碎片A。空白的部分在初始矩阵中用0表示。

1.png (./19_165f3c0a61-1.png)2.png (./19_18efab2661-2.png)

（初始矩阵A）（记忆碎片A）

请写一个算法，判定找到的记忆碎片是否是真的？


输入
输入的记忆碎片A是一个9行9列的数独矩阵。

每行包含9个数字（均不超过数字为1-9）。

初始矩阵A：

530070000

600195000

098000060

800060003

400803001

700020006

060000280

000419005

000080079


输出
如果输入数据真的是初始矩阵A的解，输出Yes，否则输出No


输入样例 1

534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179
输出样例 1

Yes
输入样例 2

123456789
123456789
123456789
123456789
123456789
123456789
123456789
123456789
123456789
输出样例 2

No
输入样例 3

534678912
672195348
198342567
859761423
42689993791
713924856
961537284
287419635
345286179
输出样例 3

No
提示

Andy(2021) (https://www.bilibili.com/video/BV1oU4y1h7hV/)
*/

#include <iostream>

#define N 9
#define M 3

using namespace std;

const short Org[N][N]= {{5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9}};

inline bool detSol(const short Sol[][N])
{
//    bool flag=true,Check[N]= {false};
    bool Check[N]= {false};
    {
        const short (*p_1)[N]=Sol,*q_1=*p_1;
        for(const short (*p_2)[N]=Org; (p_1-Sol<N)&&(p_2-Org<N); ++p_1,++p_2)
        {
            for(const short *q_2=*p_2; (q_1-*p_1<N)&&(q_2-*p_2<N); ++q_1,++q_2)
            {
                if(*q_2)
                    if(*q_1!=*q_2)
//                    {
//                        flag=false;
//                        break;
                        return false;
//                    }
                if(Check[*q_1-1])
//                {
//                    flag=false;
//                    break;
                    return false;
//                }
                else
                    Check[*q_1-1]=true;
            }
//            if(flag)
            for(bool *p=Check; p-Check<N; ++p)
                *p=false;
//            else
//                break;
        }
    }
//    if(flag)
    for(const short *p=*Sol; p-*Sol<N; ++p)
    {
        for(const short *q=p; q-*Sol<N*N; q+=N)
            if(Check[*q-1])
//                {
//                    flag=false;
//                    break;
                return false;
//                }
            else
                Check[*q-1]=true;
//            if(flag)
        for(bool *ptr=Check; ptr-Check<N; ++ptr)
            *ptr=false;
//            else
//                break;
    }
//    if(flag)
    for(const short *p=*Sol; p-*Sol<N; p+=M)
//        {
        for(const short *q=p; q-*Sol<N*N; q+=M*N)
        {
            for(const short *r=q; r-q<M*N; r+=N)
//                {
                for(const short *s=r; s-r<M; ++s)
                    if(Check[*s-1])
//                        {
//                            flag=false;
//                            break;
                        return false;
//                        }
                    else
                        Check[*s-1]=true;
//                    if(!flag)
//                        break;
//                }
//                if(flag)
            for(bool *ptr=Check; ptr-Check<N; ++ptr)
                *ptr=false;
//                else
//                    break;
        }
//            if(!flag)
//                break;
//        }
//    return flag;
    return true;
}

int main()
{
    short Sol[N][N]= {0};
    for(short (*p)[N]=Sol; p-Sol<N; ++p)
    {
        for(short *q=*p; q-*p<N; ++q)
            *q=(short)(cin.get()-'0');
        cin.get();
    }
    if(detSol(Sol))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
