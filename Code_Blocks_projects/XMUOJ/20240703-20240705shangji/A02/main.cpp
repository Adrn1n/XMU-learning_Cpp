/*
快速选择第k个数
描述

给定一个长度为n的整数数列，以及一个整数k，请用快速选择算法求出数列的第k小的数是多少。


输入
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在1--10^9范围内），表示整数数列。

数据范围:1≤n≤100000,1≤k≤n


输出
输出一个整数，表示数列的第k小数。


输入样例 1

5 3
2 4 1 5 3
输出样例 1

3
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1AK4y1S7wE)

原题链接 (https://www.acwing.com/problem/content/788/)
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
T Quickselect_k_min(const typename vector<T>::iterator Start,const typename vector<T>::iterator End,const int k)
{
    if((k>0)&&(End-Start>=k))
        if((k>1)||(Start+1<End))
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
            int i=p-Start;
            if(k<=i)
                return Quickselect_k_min<T>(Start,p,k);
            else
                return Quickselect_k_min<T>(p,End,k-i);
        }
        else
            return *Start;
    else
        return 0;
}

int main()
{
    int n,k=0;
    cin>>n>>k;
    vector<int> A(n);
    for(auto &a:A)
        cin>>a;
    cout<<Quickselect_k_min<int>(A.begin(),A.end(),k)<<endl;
    return 0;
}
