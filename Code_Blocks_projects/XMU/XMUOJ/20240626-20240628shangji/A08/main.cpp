/*
四数之和
描述

当小鲁AC了第二问，小华接着提出第三问：

给定一个目标值 target，请在整数数组 A中，找出四个元素(a,b,c,d) 使a+b+c+d==target。

请找到所有满足条件的四元组，并且请按从小到大的顺序输出所有合法的四元组。

注意：四元组中不允许包含重复数字，且输出的四元组中要求 a<b<c<d

例如:给定target = 17，n=7, 数组a= [0, 2, 5, 10, 15,18,25]

结果返回两个四元组：(0,2,5,10)


输入
输入数据为2行，第一行有两个整数 target和n，其中target代表要搜索的目标和，n表示数组A的元素个数

第二行表示数组A的n个数，每个元素用空格隔开。


输出
输出所有满足和为target的四元组(a,b,c,d) 使(a<b<c<d)并且不允许有重复数字。

把四元组按照a的大小升序输出，a相同的按照b的大小升序输出,a,b相同的按照c的大小升序输出。


输入样例 1

17 7
0 2 5 10 15 18 25
输出样例 1

0 2 5 10
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1nV411Y7wF/)
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
    for(auto it_1=A.begin(); (*it_1<target/4)&&(it_1<A.end()-3); ++it_1)
    {
        while((it_1>A.begin())&&(*it_1==*(it_1-1))&&(*it_1<target/4)&&(it_1<A.end()-3))
            ++it_1;
        for(auto it_2=it_1+1; (*it_2<(target-*it_1)/3)&&(it_2<A.end()-2); ++it_2)
        {
            while((*it_2==*it_1)&&(*it_2<(target-*it_1)/3)&&(it_2<A.end()-2))
                ++it_2;
            auto it_3=it_2+1,it_4=A.end()-1;
            while((*it_3==*it_2)&&(it_3<it_4))
                ++it_3;
            while((it_3<it_4)&&(*it_3!=*it_4))
            {
                long long val=*it_1+*it_2+*it_3+*it_4;
                if(val<target)
                    ++it_3;
                else if(val>target)
                    --it_4;
                else
                {
                    cout<<*it_1<<' '<<*it_2<<' '<<*it_3<<' '<<*it_4<<endl;
                    ++it_3,--it_4;
                }
            }
        }
    }
    return 0;
}
