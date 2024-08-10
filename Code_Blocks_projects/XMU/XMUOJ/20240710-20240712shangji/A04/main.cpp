/*
骑士林克的怜悯(2)
描述

image.png (./49550add79.png)

帮助自己的2D骑士同伴进入到变形棋盘世界不久，林克意识到既然棋盘可变，但是骑士们的战斗水平却没有长进。

虽然可以在见到更多的风景，探索更多不同的空间，但是如果自身的实力没有提升，那么骑士们感受不到那真正的自由以及成长的快乐。

林克找到去到阿卡来研究所，得到新的道具——试炼棋盘。

这个新道具可以在骑士的2D空间中创造试炼场以及2D守护者，让骑士们可以开始实战演练，提升攻击力。

如下图是一个10列11行的棋盘（11×10）：

K代表骑士的位置，H代表守护者的位置。

. 代表可移动的位置，*代表障碍物。

image.png (./7b7e6811e1.png)

骑士可以按照下图中的A,B,C,D...这条路径用5次跳跃，抵达守护者的位置偷袭它。（有可能其它路线的长度也是5）：

image.png (./dcd9484cd4.png)

请问，2D骑士要偷袭守护者，至少要跳多少次？


输入
第一行： 两个数，表示棋盘的列数Column(<=150)和行数Row(<=150)

第二行到结尾: Row行Column列的棋盘。


输出
一个数，表示跳跃的最小次数。


输入样例 1

10 11
..........
....*.....
..........
...*.*....
.......*..
..*..*...H
*.........
...*...*..
.K........
...*.....*
..*....*..
输出样例 1

5
输入样例 2

15 18
...............
..*............
...............
...*........**.
.......*.*.....
...K.*.........
...............
..**...........
.*....*......*.
........**.*...
...............
.....*......*..
.*........*....
...............
....H..........
.**.*..*.......
...............
..*....*.......
输出样例 2

6
提示

Andy讲解 (https://www.bilibili.com/video/bv14i4y1t72T)
*/

#include <iostream>
#include <queue>

#define DIM 2
#define MOV_N 8

using namespace std;

const short Move[DIM][MOV_N]= {{2,1,-1,-2,-2,-1,1,2},{-1,-2,-2,-1,1,2,2,1}};

short Min_jump_n(char A[],short M,short N)
{
    if((M>0)&&(N>0))
    {
        char *Start=A;
        bool flag_start=false,flag_tar=false;
        for(char *p=A; p-A<M*N; ++p)
            if(*p=='K')
            {
                if(flag_start)
                    return -1;
                else
                    Start=p,flag_start=true;
            }
            else if(*p=='H')
            {
                if(flag_tar)
                    return -1;
                else
                    flag_tar=true;
            }
            else if((*p!='.')&&(*p!='*'))
                return -1;
        short res=0;
        queue<char *> Cur;
        Cur.push(Start);
        do
        {
            auto num=(short)Cur.size();
            while(num--)
            {
                Start=Cur.front();
                auto x=(short)((Start-A)%N),y=(short)((Start-A)/N);
                for(short i=0; i<MOV_N; ++i)
                {
                    auto a=(short)(x+Move[0][i]),b=(short)(y+Move[1][i]);
                    if((a>=0)&&(a<N)&&(b>=0)&&(b<M))
                    {
                        char *p=A+b*N+a;
                        if(*p=='.')
                        {
                            *p='K';
                            Cur.push(p);
                        }
                        else if(*p=='H')
                            return ++res;
                    }
                }
                Cur.pop();
            }
            ++res;
        }
        while(!Cur.empty());
    }
    return -1;
}

int main()
{
    short Column=0,Row=0;
    cin>>Column>>Row;
    char A[Row][Column];
    for(char *p=*A; p-*A<Column*Row; ++p)
        cin>>*p;
    cout<<Min_jump_n(*A,Row,Column)<<endl;
    return 0;
}
