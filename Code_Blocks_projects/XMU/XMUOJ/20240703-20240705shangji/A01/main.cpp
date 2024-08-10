/*
大数排序
描述

小鲁虽然编程能力很一般，但是嘴皮子上不服输。他很喜欢拿自己不懂的问题考小华。

刚学会冒泡排序的他，决定挑战一下小华的智商：

给定你一个长度为n的整数数列。

请你对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

小鲁刻意隐瞒了数据的规模，你觉得小华能够搞定吗?

偷偷告诉你：1≤n≤100000，所有整数均在1--10^9范围内

后记：小华使用快速排序秒过，小鲁惨败，因为他看不懂小华的代码......


输入
输入共两行，第一行包含整数 n。

第二行包含 n 个整数，表示整个数列。


输出
输出共一行，包含 n 个整数，表示排好序的数列。


输入样例 1

12
111584322 907287398 13562672 615771042 83035480 323016588 501254568 158361642 388135644 58329696 400904710 38908140
输出样例 1

13562672 38908140 58329696 83035480 111584322 158361642 323016588 388135644 400904710 501254568 615771042 907287398
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1SZ4y1w7dZ)
*/

#include <iostream>
//#include <stdio.h>
#include <vector>
//#include <algorithm>

using namespace std;

template<class T>
bool quickSort(const typename vector<T>::iterator Start,const typename vector<T>::iterator End)
{
    if(Start+1<End)
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
        quickSort<T>(Start,p),quickSort<T>(p,End);
        return true;
    }
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n=0;
    cin>>n;
//    scanf("%d",&n);
//    int A[n];
    vector<int> A(n);
    for(auto &a:A)
//        scanf("%d",&a);
        cin>>a;
//    sort(A,A+n);
//    sort(A.begin(),A.end());
    quickSort<int>(A.begin(),A.end());
    for(auto &a:A)
        cout<<a<<' ';
//        printf("%d ",a);
//    printf("\n");
    cout<<endl;
    return 0;
}
