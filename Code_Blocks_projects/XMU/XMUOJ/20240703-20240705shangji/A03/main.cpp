/*
输出前k大的数
描述

给定一个数组，统计前k大的数并且把这k个数从大到小输出。


输入
第一行包含一个整数n，表示数组的大小。n < 100000。

第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。

第三行包含一个整数k。k < n。


输出
从大到小输出前k大的数，每个数一行。


输入样例 1

10
4 5 6 9 8 7 1 2 3 0
5
输出样例 1

9
8
7
6
5
提示

Andy的讲解 (https://www.bilibili.com/video/BV1sf4y1x7wF/)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4299_test_cases.zip)


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
typename vector<T>::iterator Quickselect_k2max(const typename vector<T>::iterator Start,const typename vector<T>::iterator End,const int k)
{
    if((k>0)&&(End-Start>=k))
    {
        T pivot=*Start;
        auto p=Start,q=End-1;
        while(p<=q)
        {
            while(*p<pivot)
                ++p;
            while(*q>pivot)
                --q;
            if(p<=q)
            {
                if(*p!=*q)
                    swap(*p,*q);
                if(p<End-1)
                    ++p;
                if(q>Start)
                    --q;
            }
            else
                break;
        }
        int i=End-p;
        if(k<i)
            return Quickselect_k2max<T>(p,End,k);
        else if(k>i)
            return Quickselect_k2max<T>(Start,p,k-i);
        else
            return p;
    }
    else
        return End;
}

int main()
{
    int n,k=0;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A)
        cin>>a;
    cin>>k;
    auto it=Quickselect_k2max<int>(A.begin(),A.end(),k);
    if(it!=A.end())
    {
        auto r_end=make_reverse_iterator(it);
        sort(it,A.end());
        for_each(A.rbegin(),r_end,[](int &val)
        {
            cout<<val<<endl;
        });
    }
    return 0;
}
