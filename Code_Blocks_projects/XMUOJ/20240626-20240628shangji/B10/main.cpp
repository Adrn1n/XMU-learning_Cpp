/*
2的幂次方表示
描述

image.png (./1285929844.png)


输入
一个正整数n（n≤20000）。


输出
一行，符合约定的n的0，2表示（在表示中不能有空格）。


输入样例 1

137
输出样例 1

2(2(2)+2+2(0))+2(2+2(0))+2(0)
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1PA411N7Lg)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string to_pow_2(short val)
{
    string res;
    vector<bool> pow;
    for(; val; val/=2)
        pow.push_back(val%2);
    for(auto it=pow.begin(); it<pow.end(); ++it)
        if(*it)
        {
            short tmp=(short)(it-pow.begin());
            string add;
            if(tmp!=1)
                add="2("+to_string(it-pow.begin())+')';
            else
                add='2';
            if(res.empty())
                res=add;
            else
                res=add+"+"+res;
        }
    return res;
}

//bool Trans(string &str)
//{
//    for(auto it=str.begin(); it<str.end(); ++it)
//        if((*it>='0')&&(*it<='9'))
//        {
//            short val=(short)(stoi(string(it,str.end())));
//            if((val!=2)&&(val))
//            {
//                string ins=to_pow_2(val);
//                auto r_end=it;
//                while((*r_end>='0')&&(*r_end<='9')&&(r_end<str.end()))
//                    ++r_end;
//                str.replace(it,r_end,ins);
//                it=str.begin();
//            }
//        }
//    return true;
//}

string Trans(short val)
{
    string res;
    const string pow=to_pow_2(val);
    for(auto it=pow.begin(); it<pow.end(); ++it)
    {
        bool flag=true;
        if((*it>='0')&&(*it<='9'))
        {
            short tmp=(short)(stoi(string(it,pow.end())));
            string ins;
            if((tmp!=2)&&(tmp))
            {
                ins= Trans(tmp);
                if((res.empty())||(*(res.end()-1)=='('))
                    res+=ins;
                else
                    res=res+'+'+ins;
                while(*(++it)!=')');
                --it;
                flag=false;
            }
        }
        if(flag)
            res+=*it;
    }
    return res;
}

int main()
{
//    string res;
//    cin>>res;
    short val=0;
    cin>>val;
//    Trans(res);
//    cout<<res<<endl;
    cout<<Trans(val)<<endl;
    return 0;
}
