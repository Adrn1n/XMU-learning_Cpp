/*
Dijkstra求最短路(2)
描述

给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

image.png (./eb7a99368d.png)


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

原题链接 (https://www.acwing.com/problem/content/852/)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4322_test_cases.zip)


*/

#include <iostream>
#include <queue>

#define INT_INF 0x3F3F3F3F

using namespace std;

struct Node
{
    int vertex,len;
    Node *next;
    bool operator>(const Node &b) const
    {
        return len>b.len;
    }
};

inline int Shortest_dist(Node *Nodes[],const int N)
{
    int Dist[N],dist;
    bool Set[N];
    fill(Dist,Dist+N,INT_INF),fill(Set,Set+N,false),*Dist=0;
    priority_queue<Node,vector<Node>,greater<Node>> Cur;
    Cur.push({1,0,nullptr});
    do
    {
        Node node=Cur.top();
        dist=node.len,Set[node.vertex-1]=true;
        Cur.pop();
        for(Node *p=Nodes[node.vertex-1]; p; p=p->next)
            if((!Set[p->vertex-1])&&(dist+(p->len)<Dist[p->vertex-1]))
            {
                p->len+=dist;
                Dist[p->vertex-1]=p->len,Cur.push(*p);
                p->len-=dist;
            }
    }
    while(!Cur.empty());
    if(Set[N-1])
        return Dist[N-1];
    else
        return -1;
}

int main()
{
    int n=0,m=0;
    cin>>n>>m;
    Node *Nodes[n];
    fill(Nodes,Nodes+n,nullptr);
    while(m--)
    {
        int x=0,y=0,z=0;
        cin>>x>>y>>z;
        Node *p=new Node;
        p->vertex=y,p->len=z,p->next=Nodes[x-1];
        Nodes[x-1]=p;
    }
    cout<<Shortest_dist(Nodes,n)<<endl;
    for(Node **p=Nodes; p-Nodes<n; ++p)
        while(*p)
        {
            Node *tmp=(*p)->next;
            delete *p;
            *p=tmp;
        }
    return 0;
}
