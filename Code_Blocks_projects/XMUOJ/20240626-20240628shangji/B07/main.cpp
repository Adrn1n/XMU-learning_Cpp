/*
爬天梯
描述

image.png

经过激烈的战斗，林克过关斩将终于抵达初阶递归之试炼的最后一关。
在他面前有一座天梯，天梯的顶端就是传说中的递归试炼通过证了。

林克每步可以跨一级台阶或者跨二级台阶。他必须尝试所有的走法才能得到递归试炼通过证。

如果天梯的台阶数是N，请问他总共需要尝试多少种走法？


输入
输入天梯的台阶数N。

(1<=N<=46)


输出
输出林克有几种走法。


输入样例 1

3
输出样例 1

3
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1ov411b7Lu)
*/

#include <iostream>

using namespace std;

//inline long long C_n_m(const short n,const short m)
//{
//    if(m>0)
//    {
//        long long res=1;
//        for(short i=0; i<m; ++i)
//            res*=(n-i);
//        for(short i=0; i<m; ++i)
//            res/=(m-i);
//        return res;
//    }
//    else if(!m)
//        return 1;
//    else
//        return -1;
//}
//
//inline long long Cal(const short &n_1,const short &n_2)
//{
//    long long res=0;
//    short a=max(n_1,n_2),b=min(n_1,n_2);
//    if(b)
//        for(short i=0; i<b; ++i)
//            res+=C_n_m((short)(b-1),i)*C_n_m((short)(a+1),(short)(i+1));
//    else
//        res=1;
//    return res;
//}

bool Solve(long long res[],short n)
{
    if(n>2)
    {
        if(!res[n-3])
            Solve(res,(short)(n-2));
        if(!res[n-2])
            Solve(res,(short)(n-1));
        res[n-1]=res[n-3]+res[n-2];
    }
    else if(n==2)
        res[1]=2;
    else if(n==1)
        *res=1;
    else
        return false;
    return true;
}

int main()
{
    short N=0;
    cin>>N;
//    long long res=1;
//    for(auto n_2=(short)(N/2),n_1=(short)(N-2*n_2); n_2; --n_2,n_1+=2)
//        res+=Cal(n_1,n_2);
//    cout<<res<<endl;
    if(N)
    {
        long long res[N]= {0};
        Solve(res,N);
        cout<<res[N-1]<<endl;
    }
    else
        cout<<'1'<<endl;
    return 0;
}
