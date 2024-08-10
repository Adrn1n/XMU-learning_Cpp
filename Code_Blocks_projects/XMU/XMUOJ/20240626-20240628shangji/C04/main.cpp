/*
拨钟问题
描述

有9个时钟，排成一个3*3的矩阵。

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。



移动    影响的时钟

 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI

输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。


输出
输出一个最短的时钟指针移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。


输入样例 1

3 3 0
2 2 2
2 1 2
输出样例 1

4 5 8 9
来源

http://bailian.openjudge.cn/practice/2814/
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define N 9
#define R 4

using namespace std;

typedef vector<short> hd_vec;

//inline bool Make_C_n_m(vector<hd_vec> &Ans,const short n,const short m)
//{
//    if((m<=n)&&(m>0))
//    {
//        Ans.push_back(Ans.back());
//        hd_vec &cur=Ans.back();
//        bool flag=true;
//        for(auto it_1=cur.end()-1; it_1>=cur.begin(); --it_1)
//        {
//            short tmp=(short)(cur.end()-it_1-1);
//            if(*it_1<n-tmp)
//            {
//                ++(*it_1);
//                for(auto it_2=it_1+1; it_2<cur.end(); ++it_2)
//                    *(it_2)=(short)(*(it_1)+it_2-it_1);
//                flag=false;
//                break;
//            }
//        }
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
//inline short Search_C_n_m(vector<hd_vec> &Ans,const short n,const short m)
//{
//    if((m<=n)&&(m>0)&&(Ans.empty()))
//    {
//        Ans.push_back({1});
//        for(short i=2; i<=m; ++i)
//            (Ans[0]).push_back(i);
//        short res=1;
//        while(Make_C_n_m(Ans,n,m))
//            ++res;
//        return res;
//    }
//    else
//        return 0;
//}

short Make_C_n_m(vector<hd_vec> &Ans,const short n,const short m,const short start)
{
    if(m<=n)
        if(m>0)
        {
            short cur_size=(short)Ans.size(),idx=cur_size,tmp=0;
            for(short i=start; i<start+n; idx+=tmp,tmp=0,++i)
                if((tmp=Make_C_n_m(Ans,(short)(n-(i+1-start)),(short)(m-1),(short)(i+1)))>0)
                    for(auto it=Ans.begin()+idx; it<Ans.end(); ++it)
                        (*it).push_back(i);
                else if(!tmp)
                    Ans.push_back({i}),++tmp;
                else
                    tmp=0;
            return (short)(Ans.size()-cur_size);
        }
        else
            return 0;
    else
        return -1;
}

inline short Search_C_n_m(vector<hd_vec> &Ans,const short n,const short m)
{
    if((m<=n)&&(m>0)&&(Ans.empty()))
    {
        short res=Make_C_n_m(Ans,n,m,1);
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

//inline bool Make_m_pow_n(vector<hd_vec> &Ans,const short m)
//{
//    Ans.push_back(Ans.back());
//    hd_vec &cur=Ans.back();
//    bool flag=true;
//    for(auto it_1=cur.end()-1; it_1>=cur.begin(); --it_1)
//        if(*it_1<m)
//        {
//            ++(*it_1);
//            for(auto it_2=it_1+1; it_2<cur.end(); ++it_2)
//                *it_2=1;
//            flag=false;
//            break;
//        }
//    if(flag)
//    {
//        Ans.pop_back();
//        return false;
//    }
//    else
//        return true;
//}
//
//inline int Search_m_pow_n(vector<hd_vec> &Ans,const short m,const short n)
//{
//    if((n>0)&&(m>0)&&(Ans.empty()))
//    {
//        Ans.push_back({1});
//        for(short i=1; i<n; ++i)
//            (Ans[0]).push_back(1);
//        int ans=1;
//        while(Make_m_pow_n(Ans,m))
//            ++ans;
//        return ans;
//    }
//    else
//        return 0;
//}

int Make_m_pow_n(vector<hd_vec> &Ans,const short m,const short n)
{
    if((n>0)&&(m>0))
    {
        int cur_size=(int)Ans.size(),idx=cur_size,tmp=0;
        for(short i=1; i<=m; ++i)
            if((tmp=Make_m_pow_n(Ans,m,(short)(n-1)))>0)
                for(auto it=Ans.begin()+idx; it<Ans.end(); idx+=tmp,tmp=0,++it)
                    (*it).push_back(i);
            else
                Ans.push_back({i}),++tmp;
        return (int)(Ans.size())-cur_size;
    }
    else
        return 0;
}

inline int Search_m_pow_n(vector<hd_vec> &Ans,const short m,const short n)
{
    if((n>0)&&(m>0)&&(Ans.empty()))
    {
        int res=Make_m_pow_n(Ans,m,n);
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

inline short Chg_val(short &val)
{
    return (val=(short)((val+1)%R));
}

inline bool Flip(hd_vec &A,const short flag)
{
    if(A.size()==N)
    {
        switch(flag)
        {
        case 1:
        {
            Chg_val(A[0]),Chg_val(A[1]),Chg_val(A[3]),Chg_val(A[4]);
            break;
        }
        case 2:
        {
            Chg_val(A[0]),Chg_val(A[1]),Chg_val(A[2]);
            break;
        }
        case 3:
        {
            Chg_val(A[1]),Chg_val(A[2]),Chg_val(A[4]),Chg_val(A[5]);
            break;
        }
        case 4:
        {
            Chg_val(A[0]),Chg_val(A[3]),Chg_val(A[6]);
            break;
        }
        case 5:
        {
            Chg_val(A[1]),Chg_val(A[3]),Chg_val(A[4]),Chg_val(A[5]),Chg_val(A[7]);
            break;
        }
        case 6:
        {
            Chg_val(A[2]),Chg_val(A[5]),Chg_val(A[8]);
            break;
        }
        case 7:
        {
            Chg_val(A[3]),Chg_val(A[4]),Chg_val(A[6]),Chg_val(A[7]);
            break;
        }
        case 8:
        {
            Chg_val(A[6]),Chg_val(A[7]),Chg_val(A[8]);
            break;
        }
        case 9:
        {
            Chg_val(A[4]),Chg_val(A[5]),Chg_val(A[7]),Chg_val(A[8]);
            break;
        }
        default:
            return false;
        }
        return true;
    }
    else
        return false;
}

inline int Solve(hd_vec &Ans,const hd_vec &A)
{
    if((Ans.empty())&&(A.size()==N))
    {
        for(short i=0; i<=N; ++i)
        {
            vector<hd_vec> Idx,Times;
            if(!Search_C_n_m(Idx,N,i))
            {
                hd_vec tmp;
                Idx.push_back(tmp);
            }
            if(!Search_m_pow_n(Times,R,i))
            {
                hd_vec tmp;
                Times.push_back(tmp);
            }
            for(auto it_idx=Idx.begin(); it_idx<Idx.end(); ++it_idx)
                for(auto it_times=Times.begin(); it_times<Times.end(); ++it_times)
                {
                    Ans.clear();
                    hd_vec Tmp(A);
                    bool flag=true;
                    for(auto it_1=(*it_idx).begin(),it_2=(*it_times).begin(); (it_1<(*it_idx).end())&&(it_2<(*it_times).end()); ++it_1,++it_2)
                        for(short j=0; j<*it_2; ++j)
                            Flip(Tmp,*it_1),Ans.push_back(*it_1);
                    for(auto it=Tmp.begin(); it<Tmp.end(); ++it)
                        if(*it)
                        {
                            flag=false;
                            break;
                        }
                    if(flag)
                        return (int)Ans.size();
                }
        }
        return -1;
    }
    else
        return -1;
}

int main()
{
    hd_vec A(N),Ans;
    for(auto &val:A)
        cin>>val;
    if(Solve(Ans,A)>=0)
    {
        for(auto val:Ans)
            cout<<val<<' ';
        cout<<endl;
    }
    else
        cout<<"Impossible!"<<endl;
    return 0;
}
