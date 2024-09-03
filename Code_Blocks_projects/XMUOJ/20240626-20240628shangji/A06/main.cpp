/*
两数之和
描述

双指针是极其常用的算法，这是必须学会，也是不可不会的。

但是双指针看似简单，背后的思想并不容易掌握，小华深谙此理，为了帮助小鲁一步一步的掌握这编程利器，他为小鲁精心设计了三道题：

第一题：

给定一个目标值 target，请你在不包含重复元素的按升序排列的整数数组 a中，找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。

例如:给定 a= [2, 7, 10, 15], target = 17，因为 a[1] + a[2] = 7 + 10 = 17，所以返回 [1 2]


输入
输入数据为2行，第一行有两个整数 target和n，其中target代表要搜索的目标和，n表示数组a的元素个数

第二行表示数组a的n个数，每个元素用空格隔开。


输出
输出和为target的两个元素的下标 i j ，其中(i<j)。


输入样例 1

17 7
1 3 5 7 10 11 19
输出样例 1

3 4
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1s54y1a7Qz)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long target=0,n=0;
    cin>>target>>n;
    vector<long long> A(n);
    for(auto it=A.begin(); it<A.end(); ++it)
        cin>>*it;
    auto it_f=A.begin(),it_b=A.end()-1;
    while(it_f<it_b)
    {
        long long val=*it_f+*it_b;
        if(val<target)
            ++it_f;
        else if(val>target)
            --it_b;
        else
        {
            cout<<it_f-A.begin()<<' '<<it_b-A.begin()<<endl;
            break;
        }
    }
    return 0;
}
