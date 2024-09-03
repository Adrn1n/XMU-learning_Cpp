/*
厦大GPA
描述

厦门大学的GPA (绩点)计算规则一直是同学们非常关心的问题。每门考试成绩为百分制，则分数与绩点对应关系如下:

90~100 4.0

85~89 3.7

81~84 3.3

78~80 3.0

75~77 2.7

72~74 2.3

68~71 2.0

64~67 1.7

60~63 1.0

0~59 0.0

某位同学一共参加了4门考试，给定四门考试的总分，请问在最优情况下，4门考试绩点的和最高是多少?


输入
输入4门考试的总分n，0≤n≤400。


输出
输出最优情况下，4门考试绩点之和的最高值。结果保留一位小数。


输入样例 1

400
359
59
输出样例 1

16.0
15.7
0.0
*/

#include <iostream>

using namespace std;

typedef struct
{
    short m,g;
} index_G_Mm;

const index_G_Mm table_G_Mn[10]= {{0,0},{60,10},{64,17},{68,20},{72,23},{75,27},{78,30},{81,33},{85,37},{90,40}};

short Max_G(short n)
{
    short max_G=0,G;
    for(const index_G_Mm *a=table_G_Mn; a-table_G_Mn<10; a++)
        for(const index_G_Mm *b=a; b-table_G_Mn<10; b++)
            for(const index_G_Mm *c=b; c-table_G_Mn<10; c++)
                for(const index_G_Mm *d=c; d-table_G_Mn<10; d++)
                    if(((a->m)+(b->m)+(c->m)+(d->m))>n)
                        break;
                    else
                        max_G=(((G=(short)((a->g)+(b->g)+(c->g)+(d->g)))>max_G)?G:max_G);
    return max_G;
}

int main()
{
    short n=0;
    while(cin>>n)
    {
        int r=Max_G(n);
        cout<<(r/10)<<'.'<<(r%10)<<endl;
    }
    return 0;
}
