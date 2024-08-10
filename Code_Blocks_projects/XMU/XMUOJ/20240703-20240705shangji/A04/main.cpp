/*
归并排序
描述

给定你一个长度为n的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。


输入
输入共两行，第一行包含整数 n。

第二行包含 n 个整数（所有整数均在1~109109范围内），表示整个数列。

数据范围:1≤n≤100000


输出
输出共一行，包含 n 个整数，表示排好序的数列。


输入样例 1

5
3 1 2 4 5
输出样例 1

1 2 3 4 5
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1PK411w7m8)

原题链接 (https://www.acwing.com/problem/content/790/)
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
bool mergeSort(const typename vector<T>::iterator Start,const typename vector<T>::iterator End)
{
    if(Start+1<End)
    {
        auto mid=Start+((End-Start)>>1),it_l=Start,it_r=mid;
        mergeSort<T>(Start,mid),mergeSort<T>(mid,End);
        vector<T> tmp;
        while((it_l<mid)&&(it_r<End))
            if(*it_l<*it_r)
                tmp.push_back(*it_l++);
            else
                tmp.push_back(*it_r++);
        while(it_l<mid)
            tmp.push_back(*it_l++);
        while(it_r<End)
            tmp.push_back(*it_r++);
        for(auto it_1=Start,it_2=tmp.begin(); (it_1<End)&&(it_2<tmp.end()); ++it_1,++it_2)
            *it_1=*it_2;
        return true;
    }
    else
        return false;
}

int main()
{
    int n=0;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A)
        cin>>a;
    mergeSort<int>(A.begin(),A.end());
    for(auto &a:A)
        cout<<a<<' ';
    cout<<endl;
    return 0;
}
