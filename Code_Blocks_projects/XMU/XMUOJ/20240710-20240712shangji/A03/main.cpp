/*
加农的入侵
描述

OIP (2).jpg (./38df660829.jpg)

加农是罪的化身，所到之处污秽遍地。原先富丽堂皇的海鲁拉城堡也被加农污秽了。

根据调查，加农污秽一片地区有如下规律：

下图是一个矩形区域，Y=3,X=4。

image.png (./258c8317af.png)

"."表示干净区域，而"*"表示障碍物。

如果加农一开始在左下角(1,1），那么加农将会以如下态势污染区域：

image.png (./ecfaa33929.png)

加农将在4天后污染整个区域。

设区域为矩形Y×X（1<=Y,X<=100），假设加农从(Mx,My)开始扩散，请问经过几天，加农会完全占据这个区域呢？


输入
* 第一行: 四个由空格隔开的整数: X, Y, Mx, My

* 第2到第Y+1行:每行包含一个由X个字符（"."表示干净区域，而"*"表示障碍物。）构成的字符串，共同描绘了草地的完整地图。

(1≤X,Y≤100)


输出
输出一个整数，表示加农完全占领该区域所需要的天数。


输入样例 1

4 3 1 1
....
..*.
.**.
输出样例 1

4
输入样例 2

10 10 7 5
*.........
..........
........*.
..........
.........*
..........
..........
..........
..*.......
..........
输出样例 2

6
提示

Andy的讲解 (https://www.bilibili.com/video/bv1Li4y1t7Av)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4317_test_cases.zip)


*/

#include <iostream>
#include <queue>

#define DIM 2
#define MOV_N 8

using namespace std;

const short Move[DIM][MOV_N]= {{0,0,-1,1,-1,1,-1,1},{1,-1,0,0,1,1,-1,-1}};

inline short Days_all_accessed(char A[],const short X,const short Y,const short Mx,const short My)
{
    if((X>0)&&(Y>0)&&(Mx>0)&&(My>0)&&(Mx<=X)&&(My<=Y))
    {
        short res=0;
        char *ptr=A+(Y-My)*X+Mx-1;
        *ptr='M';
        queue<char *> Cur;
        Cur.push(ptr);
        do
        {
            auto num=(short)Cur.size();
            while(num--)
            {
                ptr=Cur.front();
                auto x=(short)((ptr-A)%X+1),y=(short)(Y-(ptr-A)/X);
                for(short i=0; i<MOV_N; ++i)
                {
                    auto a=(short)(x+Move[0][i]),b=(short)(y+Move[1][i]);
                    if((a>0)&&(a<=X)&&(b>0)&&(b<=Y))
                    {
                        char *p=ptr-Move[1][i]*X+Move[0][i];
                        if(*p=='.')
                        {
                            *p='M';
                            Cur.push(p);
                        }
                        else if((*p!='*')&&(*p!='M'))
                            return -1;
                    }
                }
                Cur.pop();
            }
            ++res;
        }
        while(!Cur.empty());
        return --res;
    }
    return -1;
}

int main()
{
    short X=0,Y=0,Mx=0,My=0;
    cin>>X>>Y>>Mx>>My;
    char A[Y][X];
    for(char *p=*A; p-*A<X*Y; ++p)
        cin>>*p;
    cout<<Days_all_accessed(*A,X,Y,Mx,My)<<endl;
    return 0;
}
