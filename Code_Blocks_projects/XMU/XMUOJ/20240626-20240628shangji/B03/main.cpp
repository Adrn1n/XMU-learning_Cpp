/*
排列数字
描述

image.png (724376adb4.png)

给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

数据范围：1<=n<=7


输入
共一行，包含一个整数n。


输出
按字典序输出所有排列方案，每个方案占一行。


输入样例 1

3
输出样例 1

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1jU4y1a7m3)

原题链接 (https://www.acwing.com/problem/content/844/)
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
    short n=0;
    cin>>n;
    vector<hd_vec> Ans;
//    Search_A_n_n(Ans,n);
    Search_A_n_m(Ans,n,n);
    for(auto &ans:Ans)
    {
        for(auto &val:ans)
            cout<<val<<' ';
        cout<<endl;
    }
    return 0;
}
