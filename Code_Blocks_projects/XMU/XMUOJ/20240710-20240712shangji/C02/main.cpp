/*
滚石柱
描述

image.png (./a1ca7e018c.png)

努力练习用磁铁拖拉滚动大铁箱的林克，想起了自己小时候喜欢的一个游戏，滚石柱 (https://www.albinoblacksheep.com/games/bloxorz)。

image.png (./2f88248417.png)

这个游戏的任务是滚动一个1×1×2的长方体石柱，把它滚动到目的地。

石柱在地面上有3种放置形式，“立”在地面上（1×1的面接触地面）横“躺”或者竖“趟”在地面上（1×2的面接触地面）

image.png (./283bd916f0.png)

image.png (./2e32f16d7c.png)

迷宫是一个N行M列的矩阵，每个位置可能是硬地（用”.”表示）、易碎地面（用”E”表示）、禁地（用”#”表示）、起点（用”X”表示）或终点（用”O”表示）。

在每一步操作中，可以按上下左右四个键之一。

按下按键之后，石柱向对应的方向沿着棱滚动90度。

任意时刻，长方体不能有任何部位接触禁地，并且不能立在易碎地面上。

字符”X”标识长方体的起始位置，地图上可能有一个”X”或者两个相邻的”X”。

地图上唯一的一个字符”O”标识目标位置。

求把石柱移动到目标位置（即立在”O”上）所需要的最少步数。

在移动过程中，”X”和”O”标识的位置都可以看作是硬地被利用。


输入
输入包含多组测试用例。

对于每个测试用例，第一行包括两个整数N和M。

接下来N行用来描述地图，每行包括M个字符，每个字符表示一块地面的具体状态。

当输入用例N=0，M=0时，表示输入终止，且该用例无需考虑。

数据范围
3≤N,M≤500


输出
每个用例输出一个整数表示所需的最少步数，如果无解则输出”Impossible”。

每个结果占一行。


输入样例 1

7 7
#######
#..X###
#..##O#
#....E#
#....E#
#.....#
#######
0 0
输出样例 1

10
提示

Andy讲解 (https://www.bilibili.com/video/BV1oK411V7GF)

ACWing讲解 (https://www.acwing.com/problem/content/video/174/)

《算法竞赛进阶指南》

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4320_test_cases.zip)


*/

#include <iostream>
#include <queue>

using namespace std;

enum Rot {stand,land,port};

const short Moving[4][3][3]= {{{0,-1,port},{0,-1,land},{0,-2,stand}},{{0,2,port},{0,1,land},{0,1,stand}},{{-1,0,land},{-2,0,stand},{-1,0,port}},{{2,0,land},{1,0,stand},{1,0,port}}};

struct State
{
    short x,y,rot;
    bool operator==(const State &b)
    {
        return (x==b.x)&&(y==b.y)&&(rot=b.rot);
    }
};

inline bool Move(State &state,short moves,const short M,const short N)
{
    auto x=(short)(state.x+Moving[moves][state.rot][0]),y=(short)(state.y+Moving[moves][state.rot][1]),rot=(short)(Moving[moves][state.rot][2]);
    switch(rot)
    {
    case land:
    {
        if(x<=0)
            return false;
        break;
    }
    case port:
    {
        if(y<=0)
            return false;
        break;
    }
    default:
        break;
    }
    if((x>=0)&&(x<N)&&(y>=0)&&(y<M))
    {
        state.x=x,state.y=y,state.rot=rot;
        return true;
    }
    else
        return false;
}

inline bool Judge_state(const char A[],const short M,const short N,const State &state)
{
    if((state.x>=0)&&(state.x<N)&&(state.y>=0)&&(state.y<M))
    {
        switch(state.rot)
        {
        case stand:
        {
            if(*(A+state.y*N+state.x)=='E')
                return false;
            break;
        }
        case land:
        {
            if((!state.x)||(*(A+state.y*N+state.x-1)=='#'))
                return false;
            break;
        }
        case port:
        {
            if((!state.y)||(*(A+state.y*N+state.x-N)=='#'))
                return false;
            break;
        }
        default:
            return false;
        }
        if(*(A+state.y*N+state.x)=='#')
            return false;
        else
            return true;
    }
    else
        return false;
}

inline bool Det_init(State &state,const char A[],const short M,const short N,char c,const char *const ptr,bool &flag)
{
    auto x=(short)((ptr-A)%N),y=(short)((ptr-A)/N);
    if(flag)
    {
        if((state.x!=x)||(state.y!=y))
            flag=false;
    }
    else
    {
        if((x<N-1)&&(*(ptr+1)==c))
            state= {(short)(x+1),y,land};
        else if((y<M-1)&&(*(ptr+N)==c))
            state= {x,(short)(y+1),port};
        else
            state= {x,y,stand};
        flag=true;
    }
    return flag;
}

inline bool Init(const char A[],const short M,const short N,State &Start,State &End)
{
    bool flag_start=false,flag_end=false;
    for(const char *p=A; p-A<M*N; p+=N)
        for(const char *q=p; q-p<N; ++q)
            if(*q=='X')
            {
                if(!Det_init(Start,A,M,N,'X',q,flag_start))
                    return false;
            }
            else if(*q=='O')
            {
                if(!Det_init(End,A,M,N,'O',q,flag_end))
                    return false;
            }
            else if((*q!='E')&&(*q!='.')&&(*q!='#'))
                return false;
    return (flag_start&&flag_end);
}

inline int Min_moves(const char A[],const short M,const short N)
{
    State Start= {-1,-1,-1},End= {-1,-1,-1};
    if(Init(A,M,N,Start,End))
    {
        int Dist[3][M][N],dist=1;
        fill(**Dist,Dist[2][M-1]+N,-1),Dist[Start.rot][Start.y][Start.x]=0;
        queue<queue<State>> Step;
        queue<State> Cur;
        Cur.push(Start),Step.push(Cur);
        do
        {
            Cur=Step.front();
            queue<State> tmp_cur;
            while(!Cur.empty())
            {
                Start=Cur.front();
                for(short i=0; i<4; ++i)
                {
                    State tmp_state=Start;
                    if(Move(tmp_state,i,M,N))
                        if((Dist[tmp_state.rot][tmp_state.y][tmp_state.x]<0)&&(Judge_state(A,M,N,tmp_state)))
                        {
                            Dist[tmp_state.rot][tmp_state.y][tmp_state.x]=dist;
                            tmp_cur.push(tmp_state);
                            if(tmp_state==End)
                                return dist;
                        }
                }
                Cur.pop();
            }
            Step.pop();
            if(!tmp_cur.empty())
                Step.push(tmp_cur),++dist;
        }
        while(!Step.empty());
        return Dist[End.rot][End.y][End.x];
    }
    else
        return -1;
}

int main()
{
    short N=0,M=0;
    while(cin>>N>>M,N||M)
    {
        char A[N][M];
        for(char (*p)[M]=A; p-A<N; ++p)
        {
            cin.get();
            for(char *q=*p; q-*p<M; ++q)
                *q=(char)cin.get();
        }
        int res=Min_moves(*A,N,M);
        if(res<0)
            cout<<"Impossible"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
