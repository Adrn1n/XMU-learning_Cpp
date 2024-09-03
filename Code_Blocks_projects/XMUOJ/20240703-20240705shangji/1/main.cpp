/*
求二进制中1的个数
描述

料理.gif (./f9ed434226.gif)

为了寻找失去的回忆碎片，林克必须预备足够的料理。能够快速突破数独试炼，熟练运用lowbit，才能把难题转换为美味佳肴。

请用lowbit解决如下问题：

输入一个32位整数，输出该数二进制表示中1的个数。

注意：

负数在计算机中用其绝对值的补码来表示。

输入
输入：9
输出：2
解释：9的二进制表示是1001，一共有2个1。

输出
输入：-2
输出：31
解释：-2在计算机里会被表示成11111111111111111111111111111110，
      一共有31个1。

输入样例 1

-2
输出样例 1

31
输入样例 2

9
输出样例 2

2
提示

Andy讲解 (https://www.bilibili.com/video/BV1Kf4y1S7mB)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4308_test_cases.zip)


*/

#include <iostream>

using namespace std;

//补全下列两个函数即可
int lowbit(int n)
{
    //write your code here

    return n&(-n);
}
int NumberOf1(int n)
{
    int res = 0;
    //write your code here
    while(lowbit(n))
    {
        n-=lowbit(n);
        ++res;
    }
    return res;
}

int main()
{
    int a=0;
    cin>>a;
    cout<<NumberOf1(a)<<endl;
    return 0;
}
