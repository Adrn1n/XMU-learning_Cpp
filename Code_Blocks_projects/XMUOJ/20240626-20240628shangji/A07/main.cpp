/*
三数之和
描述

看着小鲁AC了第一题，小华接着提出第二问：

给定一个目标值 target，请在整数数组 a中，找出三个元素(x,y,z) 使x+y+z==target。

请找到所有满足条件的三元组，并且请按从小到大的顺序输出所有合法的三元组。

注意：三元组中不允许包含重复数字，且输出的三元组中要求 x<y<z.

例如:给定target = 17，n=7, 数组a= [0, 2, 7, 10, 15,18,25]

结果返回两个三元组：(0,2, 15), (2,7,10)


输入
输入数据为2行，第一行有两个整数 target和n，其中target代表要搜索的目标和，n表示数组a的元素个数

第二行表示数组a的n个数，每个元素用空格隔开。


输出
输出所有满足和为target的三元组(x,y,z)，要求(x< y <z) 并且不允许有重复数字。

把三元组按照x的大小升序输出，x相同的按照y的大小升序输出。


输入样例 1

17 7
0 2 7 10 15 18 25
输出样例 1

0 2 15
0 7 10
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1mV411v7NW)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long target=0,n=0;
    cin>>target>>n;
    vector<long long> A(n);
    for(auto it=A.begin(); it<A.end()-1; ++it)
        cin>>*it;
    sort(A.begin(),A.end());
    for(auto it_1=A.begin(); (*it_1<target/3)&&(it_1<A.end()-2); ++it_1)
    {
        while((it_1>A.begin())&&(*it_1==*(it_1-1))&&(*it_1<target/3)&&(it_1<A.end()-2))
            ++it_1;
        auto it_2=it_1+1,it_3=A.end()-1;
        while((*it_2==*it_1)&&(it_2<it_3))
            ++it_2;
        while((it_2<it_3)&&(*it_2!=*it_3))
        {
            long long val=*it_1+*it_2+*it_3;
            if(val<target)
                ++it_2;
            else if(val>target)
                --it_3;
            else
            {
                cout<<*it_1<<' '<<*it_2<<' '<<*it_3<<endl;
                ++it_2,--it_3;
            }
        }
    }
    return 0;
}
