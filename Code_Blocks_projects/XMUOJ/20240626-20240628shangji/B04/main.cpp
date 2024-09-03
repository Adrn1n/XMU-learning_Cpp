/*
字符全排列
描述

给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。


输入
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在2到8之间。


输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk, T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1= t1, s2= t2, ..., sp - 1= tp - 1, sp< tp成立。


输入样例 1

abc
输出样例 1

abc
acb
bac
bca
cab
cba
提示

需要对输入的字符串排序！

Andy讲解2021年 (https://www.bilibili.com/video/BV1Rf4y1s71T)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<short> hd_vec;
//typedef hd_vec::iterator hd_vec_it;
//
//inline hd_vec_it G_min(const hd_vec_it Start,const hd_vec_it End,const short val)
//{
//    if(Start<End)
//    {
//        hd_vec_it res=Start;
//        if(Start<End-1)
//        {
//            bool flag=true;
//            for(auto it=Start; it<End; ++it)
//                if(*it>val)
//                {
//                    flag=false;
//                    if(*it<*res)
//                        res=it;
//                }
//            if(flag)
//                res=End;
//        }
//        return res;
//    }
//    else
//        return End;
//}
//
//inline bool Make_A_n_n(vector<hd_vec> &Ans,const short n)
//{
//    if(n>0)
//    {
//        Ans.push_back(Ans.back());
//        hd_vec &tmp=Ans.back();
//        bool flag=true;
//        for(auto it_1=tmp.end()-1; it_1>tmp.begin(); --it_1)
//            if(*it_1>*(it_1-1))
//            {
//                auto it_2=G_min(it_1,tmp.end(),*(it_1-1));
//                iter_swap(it_1-1,it_2);
//                sort(it_1,tmp.end());
//                flag=false;
//                break;
//            }
//        if(flag)
//        {
//            Ans.pop_back();
//            return false;
//        }
//        else
//            return true;
//    }
//    else
//        return false;
//}
//
//inline int Search_A_n_n(vector<hd_vec> &Ans,const short n)
//{
//    if((n>0)&&(Ans.empty()))
//    {
//        Ans.push_back({1});
//        for(short i=2; i<=n; ++i)
//            (Ans[0]).push_back(i);
//        int res=1;
//        while(Make_A_n_n(Ans,n))
//            ++res;
//        return res;
//    }
//    else
//        return 0;
//}

//inline bool Make_A_n_m(vector<hd_vec> &Ans,const short n)
//{
//    if(n>0)
//    {
//        Ans.push_back(Ans.back());
//        hd_vec &cur=Ans.back();
//        bool flag_Nnext=true;
//        vector<bool> Except(n);
//        for(auto &val:cur)
//            Except[val-1]=true;
//        for(auto it_1=cur.end()-1; it_1>=cur.begin(); --it_1)
//        {
//            for(auto it=Except.begin()+*it_1; it<Except.end(); ++it)
//                if(!(*it))
//                {
//                    Except[*it_1-1]=false,*it=true,*it_1++=(short)(it-Except.begin()+1),it=Except.begin();
//                    while(it_1<cur.end())
//                    {
//                        bool flag_Nfind=true;
//                        for(; it<Except.end(); ++it)
//                            if(!(*it))
//                            {
//                                *it_1++=(short)((it++)-Except.begin()+1),flag_Nfind=false;
//                                break;
//                            }
//                        if(flag_Nfind)
//                            return false;
//                    }
//                    flag_Nnext=false;
//                    break;
//                }
//            if(flag_Nnext)
//                Except[*it_1-1]=false;
//            else
//                break;
//        }
//        if(flag_Nnext)
//        {
//            Ans.pop_back();
//            return false;
//        }
//        else
//            return true;
//    }
//    else
//        return false;
//}
//
//inline int Search_A_n_m(vector<hd_vec> &Ans,const short n,const short m)
//{
//    if((m<=n)&&(m>0)&&(Ans.empty()))
//    {
//        Ans.push_back({1});
//        for(short i=2; i<=m; ++i)
//            (Ans[0]).push_back(i);
//        int res=1;
//        while(Make_A_n_m(Ans,n))
//            ++res;
//        return res;
//    }
//    else
//        return 0;
//}

int Make_A_n_m(vector<hd_vec> &Ans,const short n,const short m,vector<bool> &Except)
{
    if(m<=n)
        if(m>0)
        {
            int cur_size=(int)Ans.size(),idx=cur_size,tmp=0;
            bool flag=false;
            for(auto it_1=Except.begin(); it_1<Except.end(); idx+=tmp,tmp=0,++it_1)
                if(!(*it_1))
                {
                    *it_1=true;
                    short val=(short)(it_1-Except.begin()+1);
                    if((tmp=Make_A_n_m(Ans,(short)(n-1),(short)(m-1),Except))>0)
                        for(auto it_2=Ans.begin()+idx; it_2<Ans.end(); ++it_2)
                            (*it_2).push_back(val);
                    else if(!tmp)
                        Ans.push_back({val}),++tmp;
                    else
                        tmp=0;
                    *it_1=false;
                    flag=true;
                }
            if(flag)
                return (int)(Ans.size()-cur_size);
            else
                return -1;
        }
        else
            return 0;
    else
        return -1;
}

inline int Search_A_n_m(vector<hd_vec> &Ans,const short n,const short m)
{
    if((m<=n)&&(m>0)&&(Ans.empty()))
    {
        vector<bool> Except(n);
        int res=Make_A_n_m(Ans,n,m,Except);
        if((unsigned long long)res==Ans.size())
        {
            for(auto &ans:Ans)
                reverse(ans.begin(),ans.end());
            return res;
        }
        else
            return -1;
    }
    else
        return 0;
}

int main()
{
    vector<char> Table;
    char c=0;
    while(cin.get(c),c!='\n')
        Table.push_back(c);
    sort(Table.begin(),Table.end());
    vector<hd_vec> Idx;
//    Search_A_n_n(Idx,(short)(Table.size()));
    Search_A_n_m(Idx,(short)(Table.size()),(short)(Table.size()));
    for(auto &idx:Idx)
    {
        for(auto &val:idx)
            cout<<Table[val-1];
        cout<<endl;
    }
    return 0;
}
