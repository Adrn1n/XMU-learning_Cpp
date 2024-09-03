/*
Dijkstra求最短路(1)
描述

给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

image.png (./ecc566c4b8.png)


输入
第一行包含整数n和m。

接下来m行每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。


输出
输出一个整数，表示1号点到n号点的最短距离。

如果路径不存在，则输出-1。


输入样例 1

3 3
1 2 2
2 3 1
1 3 4
输出样例 1

3
提示

原题链接 (https://www.acwing.com/problem/content/851/)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4321_test_cases.zip)


*/

#include <iostream>

#define INT_INF 0x3F3F3F3F

using namespace std;

inline int Shortest_dist(const short N,const int Node_dist[])
{
    int Dist[N],dist=0;
    short node=0;
    bool Checked[N];
    fill(Dist,Dist+N,INT_INF),fill(Checked+1,Checked+N,false),*Dist=0;
    while(dist<INT_INF)
    {
        Checked[node]=true;
        const int *ptr=Node_dist+node*N;
        for(short i=0; i<N; ++i)
            Dist[i]=min(Dist[i],*(ptr+i)+dist);
        dist=INT_INF;
        for(short i=0; i<N; ++i)
            if((!Checked[i])&&(Dist[i]<dist))
                dist=Dist[i],node=i;
    }
    if(Checked[N-1])
        return Dist[N-1];
    else
        return -1;
}

int main()
{
    short n=0;
    int m=0;
    cin>>n>>m;
    int Node_dist[n][n];
    fill(*Node_dist,Node_dist[n-1]+n,INT_INF);
    for(int *p=*Node_dist; p-*Node_dist<n*n; p+=n)
        *(p+(p-*Node_dist)/n)=0;
    while(m--)
    {
        short x=0,y=0;
        int z=0;
        cin>>x>>y>>z;
        Node_dist[x-1][y-1]=(Node_dist[x-1][y-1]>z)?z:Node_dist[x-1][y-1];
    }
    cout<<Shortest_dist(n,*Node_dist)<<endl;
    return 0;
}
