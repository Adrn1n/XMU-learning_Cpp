/*
英杰们的蛋糕塔
描述

查看源图像 (./th.jpg)

塞尔达公主的生日将近，英杰们预备绞尽脑汁要为公主作一个生日蛋糕塔。

这个蛋糕塔一共有N层，每层都是圆柱体，象征英杰们合一平等的关系。

蛋糕塔的总体积是 V * π 。

最底层的蛋糕半径最大，最上层的蛋糕半径最小，这种结构象征英杰们稳固的生命根基。

因此从底层往上层数，第i (1 <= i <= N) 层是半径为 r(i), 高度为h(i) 的圆柱体。当 i < N 时，有r(i) > r(i+ 1) 且 h(i) > h(i+1)。

蛋糕塔每一层圆柱体的半径r(i)和高度h(i)都是整数，象征公主英杰们不打折的忠诚。

蛋糕塔的表面积，象征英杰们与公主的亲密关系面临的外部挑战。

因此，对于给定的V和N，我们希望找到一个使表面积最小的蛋糕塔制作方案。

令表面积Q = S* π，对给定的V和N，请输出使Q最小的S是多少。

（除Q外，以上所有数据皆为正整数，下图是蛋糕塔的俯视图和示意图）

image.png (./f92aa2fa22.png)image.png (./5876ef28f6.png)


输入
有两行，第一行为V（V <= 100000），表示待制作的蛋糕的体积为V * π；第二行为N(N <= 20)，表示蛋糕的层数为N。


输出
仅一行，是一个正整数S（若无解则S = 0）。

提示：根据题意，我们无需计算π，因此有

圆柱体积v' = r*r*h
圆柱侧面积 s' = 2*r*h
圆柱底面积c'= r*r




输入样例 1

100
2
输出样例 1

68
提示

Andy讲解(B站)（更正：R和H都要逐层递减，题面无误)

（改编自《生日蛋糕》，Y总讲解(付费)）

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4306_test_cases.zip)


*/

#include <iostream>

using namespace std;

inline int Vol(int r,int h)
{
    return r*r*h;
}

inline int Side_S(int r,int h)
{
    return 2*r*h;
}

inline int Bot_S(int r)
{
    return r*r;
}

inline int N_min_V(short N)
{
    int r=N,h=N,V=0;
    while((N--)>0)
        V+=Vol(r--,h--);
    return V;
}

inline int N_min_S(short N)
{
    int r=N,h=N,S=0;
    while((N--)>0)
        S+=Side_S(r--,h--);
    return S;
}

inline int V_N_max_r(int V,short N)
{
    int r=0,h=0,v=0;
    while(--N>0)
    {
        ++r,++h;
        v+=Vol(r,h);
    }
    if((v>V)||(N<0))
        return -1;
    else
    {
        V-=v,++h;
        for(++r; (Vol(r,h)<=V); ++r);
        return r;
    }
}

inline int V_N_max_h(int V,short N)
{
    int r=0,h=0,v=0;
    while(--N>0)
    {
        ++r,++h;
        v+=Vol(r,h);
    }
    if((v>V)||(N<0))
        return -1;
    else
    {
        V-=v,++r;
        return V/(r*r);
    }
}

inline int V_r_min_S(int V,int r)
{
    return (2*V)/r;
}

int V_N_min_S(int &ans,const int V,const short N,const int pre_r,const int pre_h,const int S_under,const int Tab_min_V[],const int Tab_min_S[],const bool isBot)
{
    int S=0;
    if((V>0)&&(N>0)&&(pre_r>0)&&(pre_h>0)&&(S_under>=0))
        if((Tab_min_V[N]<=V)&&((ans<=0)||((S_under+Tab_min_S[N]<=ans)&&(S_under+V_r_min_S(V,pre_r-1)<=ans))))
            for(int h=N; h<pre_h; ++h)
                for(int r=pre_r-1; r>=N; --r)
                {
                    int v=Vol(r,h),s=Side_S(r,h),s_tmp=0;
                    if(isBot)
                        s+=Bot_S(r);
                    if((ans<=0)||((S_under+s+Tab_min_S[N-1]<=ans)&&((r<=1)||(S_under+s+V_r_min_S(V-v,r-1)<=ans))))
                        if(((v==V)&&(N==1))||((s_tmp=V_N_min_S(ans,V-v,(short)(N-1),r,h,S_under+s,Tab_min_V,Tab_min_S,false))>0))
                        {
                            s+=s_tmp;
                            if((ans<=0)||(ans>=s+S_under))
                                ans=(S=s)+S_under;
                        }
                }
    return S;
}

int main()
{
    int V=0;
    short N=0;
    cin>>V>>N;
    int Tab_min_V[N+1],Tab_min_S[N+1],ans=0;
    *Tab_min_V=N_min_V(0),*Tab_min_S=N_min_S(0);
    for(short i=1; i<=N; ++i)
        Tab_min_V[i]=Tab_min_V[i-1]+Vol(i,i),Tab_min_S[i]=Tab_min_S[i-1]+Side_S(i,i);
//    V_N_min_S(ans,V,N,V_N_max_r(V,N)+1,V_N_max_h(V,N)+1,0,Tab_min_V,Tab_min_S,true);
//    cout<<ans<<endl;
    cout<<V_N_min_S(ans,V,N,V_N_max_r(V,N)+1,V_N_max_h(V,N)+1,0,Tab_min_V,Tab_min_S,true)<<endl;
    return 0;
}
