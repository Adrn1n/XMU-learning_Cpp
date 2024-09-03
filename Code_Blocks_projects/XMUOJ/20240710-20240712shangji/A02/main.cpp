/*
波克布林的巡逻范围
描述

image.png (./6fd3a750d3.png)

有一个m行和n列的方阵区域(m＊n)，横纵坐标范围分别是0∼m−1和0∼n−1。

一只红色的波克布林从坐标0,0的格子开始巡逻，每一次只能向左，右，上，下四个方向移动一格。

但是不能进入行坐标和列坐标的数位之和大于k的格子。

请问该红色波克布林能够达到多少个格子？

假如输入：k=18, m=40, n=40

则输出是：1484

根据题意思：当k为18时，波克布林能够进入方格（35,37），因为3+5+3+7 = 18。 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。


输入
输入一行，三个整数，由空格隔开，代表k m n

其中：

0<=k<=100

0<=m<=50

0<=n<=50


输出
一个整数，表示红色波克布林能达到的多少格子。





输入样例 1

18 40 40
输出样例 1

1484
提示

Andy的讲解 (https://www.bilibili.com/video/BV1Lg4y1z73k)

ACWing讲解 (https://www.acwing.com/video/148/)

《来源：剑指Offer》

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4316_test_cases.zip)


*/

#include <iostream>
#include <queue>

#define DIM 2
#define MOV_N 4

using namespace std;

const short Move[DIM][MOV_N]= {{0,0,-1,1},{-1,1,0,0}};

inline long long Get_digits(queue<char> &ans,short val)
{
    long long cnt=0;
    if(val<0)
        val=(short)(-val);
    do
    {
        ans.push((char)(val%10)),val/=10;
        ++cnt;
    }
    while(val);
    return cnt;
}

inline short Digits_sum(queue<char> &Dig)
{
    short res=0;
    while(!Dig.empty())
        res+=Dig.front(),Dig.pop();
    return res;
}

inline short Access_N(const short m,const short n,const short k)
{
    if((m>0)&&(n>0))
        if(k>0)
        {
            short res=1;
            bool Checked[n][m];
            fill(*Checked,Checked[n-1]+m,false);
            queue<bool *> cur;
            bool *ptr=*Checked;
            *ptr=true;
            cur.push(ptr);
            do
            {
                ptr=cur.front();
                cur.pop();
                auto x=(short)((ptr-*Checked)%m),y=(short)((ptr-*Checked)/m);
                for(short i=0; i<MOV_N; ++i)
                {
                    auto a=(short)(x+Move[0][i]),b=(short)(y+Move[1][i]);
                    if((a>=0)&&(a<m)&&(b>=0)&&(b<n))
                    {
                        queue<char> Dig_a,Dig_b;
                        Get_digits(Dig_a,a),Get_digits(Dig_b,b);
                        a=Digits_sum(Dig_a),b=Digits_sum(Dig_b);
                        if(a+b<=k)
                        {
                            bool *p=ptr+Move[1][i]*m+Move[0][i];
                            if(!(*p))
                            {
                                *p=true;
                                cur.push(p),++res;
                            }
                        }
                    }
                }
            }
            while(!cur.empty());
            return res;
        }
    return 0;
}

int main()
{
    short k=0,m=0,n=0;
    cin>>k>>m>>n;
    cout<<Access_N(m,n,k)<<endl;
    return 0;
}
