/*
公主的攻击范围
描述

image.png (./fc4f8b3e16.png)

塞尔达公主瘦弱的身体里面蕴含着不可思议的神圣力量，这个力量从公主所在的位置释放，可以逐层扩散到加农污秽掌控的区域。

给定一个N行M列的区域，代号为1的区域是公主能力释放的初始区，代号为0的区域表示需要洁净的区域。

每经过1毫秒，公主的神圣之光向外扩散一格，洁净相邻区域（4个方向），请计算每个标记为0的区域中加农的势力最多还能得瑟几毫秒。

image.png (./247c7d8854.png)

格子与格子之间的距离使用曼哈顿距离计算。

提示：

image.png (./896fdea9e0.png)

根据如上公式可知：曼哈顿距离指两点之间的行坐标i距离和列坐标j距离之和。

题目的意思就是求出矩阵中所有节点为0的点，到节点为1的点的曼哈顿距离。


输入
第一行两个整数n,m。

接下来一个N行M列的01矩阵，数字之间没有空格。

数据范围
1≤N,M≤1000


输出
一个N行M列的矩阵B，相邻两个整数之间用一个空格隔开。每个整数表示加农势力存在的毫秒数（最小曼哈顿距离值）


输入样例 1

3 4
0001
0011
0110
输出样例 1

3 2 1 0
2 1 0 0
1 0 0 1
提示

Andy的讲解 (https://www.bilibili.com/video/BV1Rk4y1r7dH)

ACWing讲解 (https://www.acwing.com/problem/content/video/175/)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4319_test_cases.zip)


*/

#include <iostream>
#include <queue>

#define DIM 2
#define MOV_N 4

using namespace std;

const short Move[DIM][MOV_N]= {{1,0,-1,0},{0,1,0,-1}};

inline bool Get_Starting(queue<short *> &Starting,bool Checked[],short A[],const short M,const short N)
{
    bool flag=false;
    for(short *p=A; p-A<M*N; ++p)
        if(*p==1)
            *p=0,*(Checked+(p-A))=true,Starting.push(p),flag=true;
        else if(*p)
            return false;
    return flag;
}

inline bool Fill_min_steps(short A[],const short M,const short N)
{
    if((M>0)&&(N>0))
    {
        queue<short *> Cur;
        bool Checked[M][N];
        fill(*Checked,Checked[M-1]+N,false);
        if(Get_Starting(Cur,*Checked,A,M,N))
        {
            short dist=1;
            do
            {
                int num=(int)Cur.size();
                while(num--)
                {
                    short *ptr=Cur.front();
                    auto x=(short)((ptr-A)%N),y=(short)((ptr-A)/N);
                    for(short i=0; i<MOV_N; ++i)
                    {
                        auto a=(short)(x+Move[0][i]),b=(short)(y+Move[1][i]);
                        if((a>=0)&&(a<N)&&(b>=0)&&(b<M))
                            if(!Checked[b][a])
                            {
                                short *p=A+b*N+a;
                                Checked[b][a]=true,*p=dist,Cur.push(p);
                            }
                    }
                    Cur.pop();
                }
                ++dist;
            }
            while(!Cur.empty());
        }
    }
    return false;
}

int main()
{
    short n=0,m=0;
    cin>>n>>m;
    short A[n][m];
    for(short (*p)[m]=A; p-A<n; ++p)
    {
        cin.get();
        for(short *q=*p; q-*p<m; ++q)
            *q=(short)(cin.get()-'0');
    }
    Fill_min_steps(*A,n,m);
    for(short (*p)[m]=A; p-A<n; ++p)
    {
        for(short *q=*p; q-*p<m; ++q)
            cout<<*q<<' ';
        cout<<endl;
    }
    return 0;
}
