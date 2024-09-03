/*
汉诺塔II
描述

image.png (./8c61c1f7d1.png)

有三根杆子A，B，C。A杆上有N个(N>1)穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至C杆： 每次只能移动一个圆盘； 大盘不能叠在小盘上面。 提示：可将圆盘临时置于B杆，也可将从A杆移出的圆盘重新移回A杆，但都必须遵循上述两条规则。

问：如何移？最少要移动多少次？


输入
输入为一个整数后面跟三个单字符字符串。

整数为盘子的数目，后三个字符表示三个杆子的编号。


输出
输出每一步移动盘子的记录。一次移动一行。

每次移动的记录为例如3:a->b 的形式，即把编号为3的盘子从a杆移至b杆。

我们约定圆盘从小到大编号为1, 2, ...n。即最上面那个最小的圆盘编号为1，最下面最大的圆盘编号为n。


输入样例 1

3 a b c
输出样例 1

1:a->c
2:a->b
1:c->b
3:a->c
1:b->a
2:b->c
1:a->c
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1qy4y187N1)
*/

#include <iostream>

using namespace std;

bool Solve(short n,char src,char dest,char tmp)
{
    if(n>1)
    {
//        Solve(n-1,src,tmp,dest);
        Solve((short)(n-1),src,tmp,dest);
        cout<<n<<':'<<src<<"->"<<dest<<endl;
//        Solve(n-1,tmp,dest,src);
        Solve((short)(n-1),tmp,dest,src);
    }
    else if(n==1)
    {
        cout<<"1:"<<src<<"->"<<dest<<endl;
//        return true;
    }
    else
        return false;
    return true;
}

int main()
{
    short n=0;
    cin>>n;
    char src=0,dest=0,tmp=0;
    cin>>src>>tmp>>dest;
    Solve(n,src,dest,tmp);
    return 0;
}
