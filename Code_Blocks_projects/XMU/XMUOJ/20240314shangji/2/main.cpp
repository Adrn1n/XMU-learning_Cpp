/*
山谷数
描述

今天我们来认识一种全新的数: 山谷数。

当一个数字，从左到右依次看过去数字没有出现先递增接着递减的“山峰”现象，就称为“山谷数”。它可以递增，也可以递减，还可以先递减再递增。在递增或递减的过程中可以出现相等的情况。

比如，1，10，12，212，111，112，32122都是山谷数。 121，12331，21212则不是。


输入
输入整数n，0≤n≤2^(31−1)。


输出
如果整数n是山谷数，输出Yes，否则输出No。


输入样例 1

1
112
121
输出样例 1

Yes
Yes
No
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned a=0;
    short p,q;
    while(cin>>a)
    {
        bool IsDown=false,flag=true;
        while(a>9)
            if(flag)
            {
                p=(short)(a%10),a-=p,a/=10,q=(short)(a%10);
                if(IsDown)
                    flag=(p<=q);
                else
                    IsDown=(p<q);
            }
            else
                break;
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
