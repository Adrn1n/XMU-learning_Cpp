/*
假币问题
描述

林克有12枚银币。其中有11枚真币和1枚假币。假币看起来和真币没有区别，但是重量不同。但林克不知道假币比真币轻还是重。

于是他向他朋友约珥借了一架天平，用这架天平称了这些币三次。

如果用天平称两枚硬币，发现天平平衡，说明两枚都是真的。如果用一枚真币与另一枚银币比较，发现它比真币轻或重，说明它是假币。

经过精心的设计，聪明的林克根据这三次称量结果找出假币，并且能够确定假币是轻是重。

如果给你林克的称量数据，你也可以找出假币并且确定假币是轻是重吗？（林克提供的称量数据保证一定能找出假币）。


输入
第一行有一个数字n，表示有n组测试用例。

对于每组测试用例：

输入有三行，每行表示一次称量的结果。林克事先将银币标号为A-L。

每次称量的结果用三个以空格隔开的字符串表示：

天平左边放置的硬币  天平右边放置的硬币  平衡状态。

其中平衡状态用``up'', ``down'', 或 ``even''表示, 分别为右端高、右端低和平衡。天平左右的硬币数总是相等的。


输出
输出哪一个标号的银币是假币，并说明它比真币轻还是重(heavy or light)。


输入样例 1

1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
输出样例 1

K is the counterfeit coin and it is light.
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1kM4y1u71y)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4241_test_cases.zip)


*/

#include <iostream>
#include <string>

const short T=3,num=12;

using namespace std;

enum Status {OK=1,Light,Heavy};

struct E
{
    string l,r,state;
};

inline bool Write_Str(string &str,short val,short res[])
{
    for(auto it=str.begin(); it<str.end(); ++it)
        res[*it-'A']=val;
    return true;
}

inline bool Write_Arr(short val[],short res[],short n)
{
    for(short *p=val,*q=res; (p-val<n)&&(q-res<n); ++p,++q)
        switch(*p)
        {
        case -1:
        {
            if(!(*q))
                *q=Light;
            else if(*q==Heavy)
                *q=OK;
            break;
        }
        case 0:
        {
            *q=OK;
            break;
        }
        case 1:
        {
            if(!(*q))
                *q=Heavy;
            else if(*q==Light)
                *q=OK;
            break;
        }
        default:
            break;
        }
    return true;
}

inline bool Write_Result(string &l,string &r,short state_l,short state_r,short res[],short n)
{
    if((state_l==OK)&&(state_r==OK))
        Write_Str(l,OK,res),Write_Str(r,OK,res);
    else if((state_l==Light)&&(state_r==Heavy))
    {
        short tmp[n]= {0};
        Write_Str(l,-1,tmp),Write_Str(r,1,tmp);
        Write_Arr(tmp,res,n);
    }
    else if((state_l==Heavy)&&(state_r==Light))
    {
        short tmp[n]= {0};
        Write_Str(l,1,tmp),Write_Str(r,-1,tmp);
        Write_Arr(tmp,res,n);
    }
    return true;
}

int main()
{
    long long n=0;
    cin>>n;
    while(n--)
    {
        E e;
        short C[num]= {0},*res=C;
        for(short i=0; i<T; ++i)
        {
            cin>>e.l>>e.r>>e.state;
            if(e.state=="even")
            {
                if(e.l.size()>e.r.size())
                    Write_Result(e.l,e.r,Light,Heavy,C,num);
                else if(e.l.size()<e.r.size())
                    Write_Result(e.l,e.r,Heavy,Light,C,num);
                else
                    Write_Result(e.l,e.r,OK,OK,C,num);
            }
            else if(e.state=="up")
            {
                if(e.l.size()<=e.r.size())
                    Write_Result(e.l,e.r,Heavy,Light,C,num);
            }
            else if(e.state=="down")
            {
                if(e.l.size()>=e.r.size())
                    Write_Result(e.l,e.r,Light,Heavy,C,num);
            }
        }
        e.state.clear();
        for(short *p=C; p-C<num; ++p)
            if(*p==Light)
            {
                if(e.state.empty())
                    res=p,e.state="light";
                else
                {
                    e.state.clear();
                    break;
                }
            }
            else if(*p==Heavy)
            {
                if(e.state.empty())
                    res=p,e.state="heavy";
                else
                {
                    e.state.clear();
                    break;
                }
            }
            else if(!(*p))
            {
                e.state.clear();
                break;
            }
        if(e.state.empty())
            cout<<"Can't determine yet."<<endl;
        else
            cout<<(char)('A'+res-C)<<" is the counterfeit coin and it is "<<e.state<<". "<<endl;
    }
    return 0;
}
