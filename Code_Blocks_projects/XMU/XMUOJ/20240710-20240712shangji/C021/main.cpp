/*
突袭路线
描述

image.png (./d3817e11ae.png)

为了解救公主，林克必须深入敌后。
在备战前，他拿出“关系分析仪”扫描敌营中每个士兵之间的关系。

关系分析仪的功能说明如下：
如果A的活动范围在B的眼皮底下，那么分析仪就会从B出发连一条射线指向A（B-->A).

经过扫描，林克得到全营敌兵的相互关系。有些敌人被多个同伴看顾，有些敌人背后一个替他守望的都没有。

林克决定从背后没有人的敌人开始，潜伏到其背后，突袭之，并且避免被其他人发现。

军营一共有n个敌人，彼此之间的关系有m条射线，请找到一条可以逐个击破敌人的路线图。

如果找不到这样一条突袭路线，请则输出-1.


提示：
问题转化为：给定一个n个点m条边的有向图，点的编号是1到n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。

若一个由图中所有点构成的序列A满足：对于图中的每条边(x, y)，x在A中都出现在y之前，则称A是该图的一个拓扑序列。

数据范围：1≤n,m≤10^5


输入
第一行包含两个整数n和m

接下来m行，每行包含两个整数x和y，表示存在一条从点x到点y的有向边(x, y)。


输出
共一行，如果存在拓扑序列，则输出拓扑序列。

否则输出-1。


输入样例 1

3 3
1 2
2 3
1 3
输出样例 1

1 2 3
提示

Andy讲解 (https://www.bilibili.com/video/BV1x5411s7ev)

acwing讲解 (https://www.acwing.com/video/280/)

改编自《有向图的拓扑序列》 (https://www.acwing.com/problem/content/description/850/)
*/

#include <iostream>

using namespace std;

struct Node
{
    int vertex;
    Node *next;
};

inline bool Topological_sort(int Ans[],Node *Nodes[],int Indegree[],const int N)
{
    int cnt=0;
    for(int *p=Indegree; p-Indegree<N; ++p)
        if(!(*p))
            Ans[cnt++]=(int)(p-Indegree+1);
    for(int i=0; (i<cnt)&&(cnt<=N); ++i)
        for(Node *node=Nodes[Ans[i]-1]; node; node=node->next)
        {
            int tmp=node->vertex;
            --Indegree[tmp-1];
            if(!Indegree[tmp-1])
                Ans[cnt++]=tmp;
        }
    if(cnt==N)
        return true;
    else
        return false;
}

int main()
{
    int n=0,m=0;
    cin>>n>>m;
    Node *Nodes[n];
    int Indegree[n],Ans[n];
    fill(Nodes,Nodes+n,nullptr),fill(Indegree,Indegree+n,0);
    while(m--)
    {
        int x=0,y=0;
        cin>>x>>y;
        Node *p=new Node;
        p->vertex=y,p->next=Nodes[x-1];
        Nodes[x-1]=p;
        ++Indegree[y-1];
    }
    if(Topological_sort(Ans,Nodes,Indegree,n))
    {
        for(int *p=Ans; p-Ans<n; ++p)
            cout<<*p<<' ';
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;
    for(Node **p=Nodes; p-Nodes<n; ++p)
        while(*p)
        {
            Node *tmp=(*p)->next;
            delete *p;
            *p=tmp;
        }
    return 0;
}
