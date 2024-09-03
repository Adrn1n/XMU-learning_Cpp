/*
二进制密码锁
描述

image.png (./256a24f724.png)

在海拉鲁大陆有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，林克至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。


输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。


输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。


输入样例 1

011
000
输出样例 1

1
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1Zi4y1N7dU)
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> bol_vec;

bool Flip(bol_vec &A,bol_vec::iterator place)
{
    if((place>=A.begin())&&(place<A.end()))
    {
        *place=!(*place);
        if(place>A.begin())
            *(place-1)=!(*(place-1));
        if(place<A.end()-1)
            *(place+1)=!(*(place+1));
        return true;
    }
    else
        return false;
}

int Cnt_steps(const bol_vec &Org,const bol_vec &Tar)
{
    if(Org.size()==Tar.size())
    {
        int res_1=0,res_2=1,res;
        bol_vec Tmp=(Org);
        auto it_1=Tar.begin();
        for(auto it_2=Tmp.begin(); (it_1<Tar.end()-1)&&(it_2<Tmp.end()-1); ++it_1,++it_2)
            if(*it_1!=*it_2)
            {
                Flip(Tmp,it_2+1);
                ++res_1;
            }
        if(*(Tmp.end()-1)!=*(Tar.end()-1))
            res_1=-1;
        Tmp=Org;
        Flip(Tmp,Tmp.begin());
        it_1=Tar.begin();
        for(auto it_2=Tmp.begin(); (it_1<Tar.end()-1)&&(it_2<Tmp.end()-1); ++it_1,++it_2)
            if(*it_1!=*it_2)
            {
                Flip(Tmp,it_2+1);
                ++res_2;
            }
        if(*(Tmp.end()-1)!=*(Tar.end()-1))
            res_2=-1;
        if((res=min(res_1,res_2))>=0)
            return res;
        else
            return max(res_1,res_2);
    }
    else
        return -1;
}

int main()
{
    bol_vec Org,Tar;
    int res;
    while((res=cin.get())!='\n')
        Org.push_back(res-'0');
    while((res=cin.get())!='\n')
        Tar.push_back(res-'0');
    res=Cnt_steps(Org,Tar);
    if(res>=0)
        cout<<res<<endl;
    else
        cout<<"impossible"<<endl;
    return 0;
}
