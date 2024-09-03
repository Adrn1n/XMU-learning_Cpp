/*
净化迷雾森林
描述

image.png (./3ec4db1361 (1).png)

迷雾森林被加农的玷污了，原本圣洁无比的迷雾森林，如今被彻底玷污，空气中充满着紫色的恶臭。

林克临危不惧，带上呼吸面罩，挥舞大师之剑的光芒，净化迷雾。林克所到之处，加农褪去，圣洁回归。

如下图，红色代表墙壁，紫色的迷雾代表需要净化的空间，金色代表林克开始净化的起点。

从某处开始，林克只能向相邻的紫色区域移动。请问，林克总共能够净化多少区域？

图1 初始状态                                                                图2   净化中.....

image.png (./f48cf16664 (1).png)-----image.png (./d72a7d4360 (1).png)


输入
包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。

在接下来的H行中，每行包括W个字符。

每个字符表示一个区域的状态，规则如下

1）‘.’：代表紫色迷雾image.png (./668de4a15e (1).png)；

2）‘#’：代表红墙image.png (./65762c10c1 (1).png)；

3）‘@’：代表林克的起始位置image.png (./bb1c64a143 (1).png)(该字符在每个数据集合中唯一出现一次。）

当在一行中读入的是两个零时，表示输入结束。


输出
对每个数据集合，分别输出一行，显示林克从初始位置出发能净化的迷雾数(记数时包括初始位置的迷雾)。


输入样例 1

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
0 0
输出样例 1

45
提示

Andy(2021) (https://www.bilibili.com/video/BV1r64y1v7ot?pop_share=1)

Andy(2020) (https://www.bilibili.com/video/BV13T4y1G7HP)

（改编自《红与黑 (http://cxsjsxmooc.openjudge.cn/2020t2springall/018/)》）

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4315_test_cases.zip)


*/

#include <iostream>
#include <queue>

#define DIM 2
#define MOV_N 4

using namespace std;

const short Move[DIM][MOV_N]= {{0,0,-1,1},{-1,1,0,0}};

inline short Max_Clean(char A[],const short W,const short H)
{
    if((W>0)&&(H>0))
    {
        char *ptr=A;
        bool flag=false;
        for(char *p=A; p-A<W*H; ++p)
            if(*p=='@')
            {
                if(flag)
                    return -1;
                else
                    ptr=p,flag=true;
            }
        if(flag)
        {
            short res=1;
            queue<char *> cur;
            cur.push(ptr);
            do
            {
                char *p=cur.front();
                cur.pop();
                auto x=(short)((p-A)%W+1),y=(short)((p-A)/W+1);
                for(short i=0; i<MOV_N; ++i)
                {
                    auto a=(short)(x+Move[0][i]),b=(short)(y+Move[1][i]);
                    if((a>0)&&(a<=W)&&(b>0)&&(b<=H))
                    {
                        char *tmp=p+Move[1][i]*W+Move[0][i];
                        if(*tmp=='.')
                        {
                            *tmp='#';
                            cur.push(tmp),++res;
                        }
                    }
                }
            }
            while(!cur.empty());
            return res;
        }
        else
            return 0;
    }
    else
        return -1;
}

int main()
{
    short W=0,H=0;
    while(cin>>W>>H,W||H)
    {
        char A[H][W];
        for(char *p=*A; p-*A<W*H; ++p)
            cin>>*p;
        cout<<Max_Clean(*A,W,H)<<endl;
    }
    return 0;
}
