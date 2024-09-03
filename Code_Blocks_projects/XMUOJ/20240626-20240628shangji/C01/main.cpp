/*
算24
描述

image.png (./b54dd9013d.png)

林克来到怪物商店，决定开始挑战一道难题：算24！

题目是：给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。

现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。

这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。

比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。

注意：输入数字的次序可以改变。


输入
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。


输出
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。


输入样例 1

5 5 5 1
1 1 4 2
0 0 0 0
输出样例 1

YES
NO
提示

Andy的讲解(2020) (https://www.bilibili.com/video/BV12E411E7u9)
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define N 4

using namespace std;

inline short gcd(short a,short b)
{
    short tmp=b;
    if(a<b)
        b=a,a=tmp;
    while(b)
        tmp=b,b=(short)(a%b),a=tmp;
    return a;
}

struct Q
{
    short numerator;
    short denominator;
    inline bool Simplify()
    {
        short tmp=gcd(numerator,denominator);
        if(tmp)
        {
            numerator/=tmp,denominator/=tmp;
            return true;
        }
        else
            return false;
    }
    Q operator+(Q &b) const
    {
        Q c{};
        c.denominator=(short)(denominator*b.denominator);
        c.numerator=(short)(numerator*b.denominator+b.numerator*denominator);
        c.Simplify();
        return c;
    }
    Q operator-(Q &b) const
    {
        Q c{};
        c.denominator=(short)(denominator*b.denominator);
        c.numerator=(short)(numerator*b.denominator-b.numerator*denominator);
        c.Simplify();
        return c;
    }
    Q operator*(Q &b) const
    {
        Q c{};
        c.denominator=(short)(denominator*b.denominator);
        c.numerator=(short)(numerator*b.numerator);
        c.Simplify();
        return c;
    }
    Q operator/(Q &b) const
    {
        Q c{};
        c.denominator=(short)(denominator*b.numerator);
        c.numerator=(short)(numerator*b.denominator);
        c.Simplify();
        return c;
    }
};

typedef vector<Q> Q_vec;
typedef Q_vec::iterator Q_vec_it;
typedef vector<short> hd_vec;
//typedef hd_vec::iterator hd_vec_it;

bool Cal(Q_vec &Res,const Q_vec_it Start,const Q_vec_it End)
{
    if((Start+1)<(End-1))
        for(auto it=Start+1; it<End; ++it)
        {
            Q_vec L,R;
            Cal(L,Start,it);
            Cal(R,it,End);
            for(auto it_L=L.begin(); it_L<L.end(); ++it_L)
                for(auto it_R=R.begin(); it_R<R.end(); ++it_R)
                {
                    Q_vec A= {*it_L,*it_R};
                    Cal(Res,A.begin(),A.end());
                }
        }
    else if((Start+1)==(End-1))
    {
        Res.push_back((*Start)+(*(Start+1)));
        Res.push_back((*Start)-(*(Start+1)));
        Res.push_back((*Start)*(*(Start+1)));
        if((*(Start+1)).numerator)
            Res.push_back((*Start)/(*(Start+1)));
    }
    else if((Start+1)==End)
        Res.push_back(*Start);
    else
        return false;
    return true;
}

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
    while(true)
    {
        Q_vec A(N);
        for(auto it=A.begin(); it<A.end(); ++it)
            cin>>(*it).numerator,(*it).denominator=1;
        bool flag=true;
        for(auto it=A.begin(); it<A.end(); ++it)
            if((*it).numerator)
            {
                flag=false;
                break;
            }
        if(flag)
            break;
        else
        {
            vector<hd_vec> Idx;
//            Search_A_n_n(Idx,N);
            Search_A_n_m(Idx,N,N);
            for(auto it_1=Idx.begin(); it_1<Idx.end(); ++it_1)
            {
                Q_vec Res,Tmp(N);
                for(auto it_2=(*it_1).begin(); it_2<(*it_1).end(); ++it_2)
                    Tmp[it_2-(*it_1).begin()]=A[*it_2-1];
                Cal(Res,Tmp.begin(),Tmp.end());
                for(auto it=Res.begin(); it<Res.end(); ++it)
                    if(((*it).numerator==24)&&((*it).denominator==1))
                    {
                        cout<<"YES"<<endl;
                        flag=true;
                        break;
                    }
                if(flag)
                    break;
            }
            if(!flag)
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
