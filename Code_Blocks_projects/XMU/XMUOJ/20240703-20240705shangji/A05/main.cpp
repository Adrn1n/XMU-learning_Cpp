/*
求排列的逆序数
描述

在Internet上的搜索引擎经常需要对信息进行比较，比如可以通过某个人对一些事物的排名来估计他（或她）对各种不同信息的兴趣，从而实现个性化的服务。

对于不同的排名结果可以用逆序来评价它们之间的差异。考虑1,2,…,n的排列i1，i2，…，in，如果其中存在j,k，满足 j < k 且ij> ik， 那么就称(ij,ik)是这个排列的一个逆序。

一个排列含有逆序的个数称为这个排列的逆序数。

例如排列 263451 含有8个逆序(2,1),(6,3),(6,4),(6,5),(6,1),(3,1),(4,1),(5,1)，因此该排列的逆序数就是8。

显然，由1,2,…,n 构成的所有n!个排列中，最小的逆序数是0，对应的排列就是1,2,…,n；最大的逆序数是n(n-1)/2，对应的排列就是n,(n-1),…,2,1。

逆序数越大的排列与原始排列的差异度就越大。

现给定1,2,…,n的一个排列，求它的逆序数。


输入
第一行是一个整数n，表示该排列有n个数（n <= 100000)。

第二行是n个不同的正整数，之间以空格隔开，表示该排列。


输出
输出该排列的逆序数。


输入样例 1

6
2 6 3 4 5 1
输出样例 1

8
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV14X4y1G77n)

Andy的讲解(2020) (https://www.bilibili.com/video/av95376969)

逆序数可能很多，使用long long存储
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
long long mergeSort(const typename vector<T>::iterator Start,const typename vector<T>::iterator End)
{
    if(Start+1<End)
    {
        long long res;
        auto mid=Start+((End-Start)>>1),it_l=Start,it_r=mid;
        res=mergeSort<T>(Start,mid)+mergeSort<T>(mid,End);
        vector<T> tmp;
        while((it_l<mid)&&(it_r<End))
            if(*it_l<=*it_r)
                tmp.push_back(*it_l++);
            else
                res+=mid-it_l,tmp.push_back(*it_r++);
        while(it_l<mid)
            tmp.push_back(*it_l),++it_l;
        while(it_r<End)
            tmp.push_back(*it_r),++it_r;
        for(auto it_1=Start,it_2=tmp.begin(); (it_1<End)&&(it_2<tmp.end()); ++it_1,++it_2)
            *it_1=*it_2;
        return res;
    }
    else
        return 0;
}

int main()
{
    int n=0;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A)
        cin>>a;
    cout<<mergeSort<int>(A.begin(),A.end())<<endl;
    return 0;
}
