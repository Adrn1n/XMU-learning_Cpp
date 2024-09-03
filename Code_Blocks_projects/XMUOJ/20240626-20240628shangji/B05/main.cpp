/*
输出N皇后的全部摆法
描述

随着编程水平的进阶，小华知道是全面扩充小鲁知识面，帮助他快速升级的时候到了，他再给小鲁布置了道经典题：

输入一个正整数N，请写一个程序，输出N皇后问题的全部摆法。


输入
输入皇后的个数n（n<=13）


输出
输出长度为n的正整数。

输出结果里的每一行都代表一种摆法。

行里的第i个数字如果是n，就代表第i行的皇后应该放在第n列。

皇后的行、列编号都是从1开始算。


输入样例 1

4
输出样例 1

2413
3142

提示

Andy的讲解(2021) (https://www.bilibili.com/video/BV1X64y1D7fg)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<short> hd_vec;

inline bool Check_diag(const hd_vec::const_iterator Start,const hd_vec::const_iterator End)
{
    for(auto it_1=Start; it_1<End-1; ++it_1)
        for(auto it_2=it_1+1; it_2<End; ++it_2)
            if((it_2-it_1==(*it_2)-(*it_1))||(it_2-it_1==(*it_1)-(*it_2)))
                return false;
    return true;
}

bool Solve(vector<hd_vec> &Ans,hd_vec Res,vector<bool> Except,const short m,const short n)
{
    if((m<=n)&&(m>=0))
    {
        if(m>0)
        {
            for(auto it=Except.begin(); it<Except.end(); ++it)
                if(!(*it))
                {
                    Res[n-m]=it-Except.begin()+1;
                    if(Check_diag(Res.begin(),Res.begin()+n-m+1))
                    {
                        *it=true;
                        Solve(Ans,Res,Except,m-1,n);
                        *it=false;
                    }
                }
        }
        else
            Ans.push_back(Res);
        return true;
    }
    else
        return false;
}

int main()
{
    short n=0;
    cin>>n;
    vector<hd_vec> Ans;
    hd_vec Tmp(n);
    vector<bool> Except(n);
    if(Solve(Ans,Tmp,Except,n,n))
        for(auto &ans:Ans)
        {
            for(auto &val:ans)
                cout<<val;
            cout<<endl;
        }
    else
        cout<<"ERROR"<<endl;
    return 0;
}
