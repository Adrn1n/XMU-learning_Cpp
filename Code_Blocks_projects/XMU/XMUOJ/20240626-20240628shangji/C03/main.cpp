/*
熄灯问题
描述

有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。每个按钮的位置上有一盏灯。当按下一个按钮后，该按钮以及周围位置(上边、下边、左边、右边)的灯都会改变一次。即，如果灯原来是点亮的，就会被熄灭；如果灯原来是熄灭的，则会被点亮。在矩阵角上的按钮改变3盏灯的状态；在矩阵边上的按钮改变4盏灯的状态；其他的按钮改变5盏灯的状态。

(./2811_1.jpg)

在上图中，左边矩阵中用X标记的按钮表示被按下，右边的矩阵表示灯状态的改变。对矩阵中的每盏灯设置一个初始状态。请你按按钮，直至每一盏等都熄灭。与一盏灯毗邻的多个按钮被按下时，一个操作会抵消另一次操作的结果。在下图中，第2行第3、5列的按钮都被按下，因此第2行、第4列的灯的状态就不改变。

(./2811_2.jpg)

请你写一个程序，确定需要按下哪些按钮，恰好使得所有的灯都熄灭。根据上面的规则，我们知道1）第2次按下同一个按钮时，将抵消第1次按下时所产生的结果。因此，每个按钮最多只需要按下一次；2）各个按钮被按下的顺序对最终的结果没有影响；3）对第1行中每盏点亮的灯，按下第2行对应的按钮，就可以熄灭第1行的全部灯。如此重复下去，可以熄灭第1、2、3、4行的全部灯。同样，按下第1、2、3、4、5列的按钮，可以熄灭前5列的灯。


输入
5行组成，每一行包括6个数字（0或1）。

相邻两个数字之间用单个空格隔开。

0表示灯的初始状态是熄灭的，1表示灯的初始状态是点亮的。


输出
5行组成，每一行包括6个数字（0或1）。

相邻两个数字之间用单个空格隔开。

其中的1表示需要把对应的按钮按下，0则表示不需要按对应的按钮。


输入样例 1

2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
输出样例 1

PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
PUZZLE #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1

注意：PUZZLE行结尾没有空格，数字行最后有一个空格。
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV1QK4y1J7en)
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define M 5
#define N 6

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

inline bool Flip(bool Org[],const short m,const short n,const short x,const short y)
{
    if((m>0)&&(n>0)&&(x>=0)&&(x<n)&&(y>=0)&&(y<m))
    {
        bool *ptr=Org+y*n+x;
        *ptr=!(*ptr);
        if(x>0)
            *(ptr-1)=!(*(ptr-1));
        if(x<n-1)
            *(ptr+1)=!(*(ptr+1));
        if(y>0)
            *(ptr-n)=!(*(ptr-n));
        if(y<m-1)
            *(ptr+n)=!(*(ptr+n));
        return true;
    }
    else
        return false;
}

bool Solve(bool Res[],const bool Org[],const short m,const short n)
{
    if((m>0)&&(n>0))
        for(short i=0; i<=n; ++i)
        {
            vector<hd_vec> Idx;
            if(!Search_C_n_m(Idx,n,i))
            {
                hd_vec tmp;
                Idx.push_back(tmp);
            }
            for(auto it_1=Idx.begin(); it_1<Idx.end(); ++it_1)
            {
                bool Tmp[m][n],flag=true;
                copy(Org,Org+m*n,*Tmp);
                bool Ans[m][n];
                fill(*Ans,Ans[m-1]+n,false);
                for(auto it_2=(*it_1).begin(); it_2<(*it_1).end(); ++it_2)
                    Flip(*Tmp,m,n,(short)(*it_2-1),0),Ans[0][*it_2-1]=true;
                for(const bool(*p)[n]=Tmp; p-Tmp<m-1; ++p)
                    for(const bool *q=*p; q-*p<n; ++q)
                        if(*q)
                            Flip(*Tmp,m,n,(short)(q-*p),(short)(p-Tmp+1)),Ans[p-Tmp+1][q-*p]=true;
                for(const bool *p=Tmp[m-1]; p-Tmp[m-1]<n; ++p)
                    if(*p)
                    {
                        flag=false;
                        break;
                    }
                if(flag)
                {
                    for(bool *p=Res,*q=*Ans; (p-Res<m*n)&&(q-*Ans<m*n); ++p,++q)
                        *p=*q;
                    return true;
                }
            }
        }
    return false;
}

int main()
{
    long long T=0,t=0;
    cin>>T;
    while(++t<=T)
    {
        bool Org[M][N]= {false},Res[M][N]= {false};
        for(bool (*p)[N]=Org; p-Org<M; ++p)
            for(bool *q=*p; q-*p<N; ++q)
                cin>>*q;
        cout<<"PUZZLE #"<<t<<endl;
        if(Solve(*Res,*Org,M,N))
            for(bool (*p)[N]=Res; p-Res<M; ++p)
            {
                for(bool *q=*p; q-*p<N; ++q)
                    cout<<*q<<' ';
                cout<<endl;
            }
        else
            cout<<"Impossible!"<<endl;
    }
    return 0;
}
