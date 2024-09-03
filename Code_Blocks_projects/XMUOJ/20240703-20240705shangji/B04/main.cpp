/*
击杀黄金蛋糕人马
描述

在海拉鲁大陆冒险，没有绝佳的剑法+想象力是不可能存活下来的。

这不，林克遇到了一个特别巨大的敌人——黄金蛋糕人马（莱尼尔的变种）

这黄金蛋糕人马长相非常特别，没有脚没有手没有嘴巴没有头，整个身材就是一个大矩形（喂喂，这不就是黄金莱尼尔吗？）

image.png (./c566399d7b.png)
它的长和宽分别是整数w、h。

林克举起大师之剑，挥向黄金蛋糕人马，要将其切成m块矩形小块打包走，分给自己的朋友（每块都必须是矩形、且长和宽均为整数）。

大师之剑无比锐利，每一斩带出的剑气能将黄金蛋糕人马劈成两半（形成两个小矩形蛋糕）。

经过m-1斩，黄金蛋糕人马居然被劈成m块小蛋糕（喂喂，你的想象力也太丰富了，明明切不开好吗？）

请计算：最后得到的m块小蛋糕中，最大的那块蛋糕的面积下限。


假设w= 4,h= 4,m= 4，则下面的斩击可使得其中最大蛋糕块的面积最小。(十字斩)

(./1372385654.gif)

假设w= 4,h= 4,m= 3，则下面的斩击可使得其中最大蛋糕块的面积最小:.(二连斩)

(./1372385663.gif)


输入
共有多行，每行表示一个测试案例。

每行是三个用空格分开的整数w, h, m ，其中1 ≤ w, h, m ≤ 20 ， m ≤ wh.

当 w = h = m = 0 时不需要处理，表示输入结束。


输出
每个测试案例的结果占一行，输出一个整数，表示最大蛋糕块的面积下限。


输入样例 1

4 4 4
4 4 3
0 0 0
输出样例 1

4
6
提示

Andy讲解 (https://www.bilibili.com/video/BV1ti4y1b7s1)

改编自《分蛋糕 (https://www.bilibili.com/video/BV1Zb411q7iY?p=33)》

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4307_test_cases.zip)


*/

#include <iostream>

#define W 20
#define H 20

using namespace std;

short Res[W*H+1][H][W]= {0};

short Max_min(const short w,const short h,const short m)
{
    if((w>0)&&(h>0)&&(m>=0)&&(m<=w*h))
    {
        auto res=(short)(w*h);
        if(m)
        {
            for(short i=1; i<(short)(w/2+1); ++i)
                for(short j=0; j<m; ++j)
                {
                    if(Res[j][h-1][i-1]==-2)
                        Res[j][h-1][i-1]=Max_min(i,h,j);
                    if(Res[m-1-j][h-1][w-i-1]==-2)
                        Res[m-1-j][h-1][w-i-1]=Max_min((short)(w-i),h,(short)(m-1-j));
                    res=min(res,max(Res[j][h-1][i-1],Res[m-1-j][h-1][w-i-1]));
                }
            for(short i=1; i<(short)(h/2+1); ++i)
                for(short j=0; j<m; ++j)
                {
                    if(Res[j][i-1][w-1]==-2)
                        Res[j][i-1][w-1]=Max_min(w,i,j);
                    if(Res[m-1-j][h-i-1][w-1]==-2)
                        Res[m-1-j][h-i-1][w-1]=Max_min(w,(short)(h-i),(short)(m-1-j));
                    res=min(res,max(Res[j][i-1][w-1],Res[m-1-j][h-i-1][w-1]));
                }
        }
        Res[m][h-1][w-1]=res;
        return res;
    }
    else
        return -1;
}

int main()
{
    for(short *p=Res[0][0]; p-Res[0][0]<W*H*(W*H+1); ++p)
        *p=-2;
    short w=0,h=0,m=0;
    while(cin>>w>>h>>m,w||h||m)
        cout<<Max_min(w,h,(short)(m-1))<<endl;
    return 0;
}
