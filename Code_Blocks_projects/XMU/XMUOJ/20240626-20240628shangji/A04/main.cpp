/*
排序考试
描述

处于某种原因，一点都不懂编程的某某系小迅老师竟然成功跳槽到计算机系来教大一新生如何编程。

看着这位在台上胡言乱语，水平比同学小华弱太多的老师，小鲁简直不忍直视。

那学期的期中考试，小讯老师出的题目竟然是：“请写一个排序算法给数组排序，结果按照升序输出。”

经过NQ49斩的小鲁分分钟就完成了代码。小讯老师一看，哎呀不得了，得提高期中考试难度。

他立刻把题目改为：“给定任意T组整数，每组整数都要按升序输出。”

小鲁笑了笑，原来这类题已经难不倒他了，原来他早就超过了大一上小讯老师的水平了！

小鲁水平进阶了，你做得到吗？


输入
第一行是整数T，表示一共有T组数据。

接下来T行，每行有N+1个数，第一个整数表示该行有N个待排序的数字。

整数N(1<=N<=1000000），T（1<=T<=100）。


输出
对于每组整数，按照升序输出排序结果，每个结果占一行。


输入样例 1

3
4 412 120 5560 3760
5 576 66 35 99 88
4 127 100 510 380
输出样例 1

120 412 3760 5560
35 66 88 99 576
100 127 380 510
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    short T=0;
    cin>>T;
    while(T--)
    {
        int N=0;
        cin>>N;
        vector<int> A(N);
        auto it=A.begin();
        for(; it<A.end(); ++it)
            cin>>*it;
        sort(A.begin(),A.end());
        it=A.begin();
        for(; it<A.end()-1; ++it)
            cout<<*it<<' ';
        cout<<*it<<endl;
    }
    return 0;
}
