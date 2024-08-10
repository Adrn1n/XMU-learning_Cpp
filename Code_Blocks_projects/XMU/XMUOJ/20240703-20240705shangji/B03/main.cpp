/*
骑士林克的怜悯(1)
描述


image.png (./b6774f404c.png)

林克驰骋在海拉鲁大陆的平原上无比自由，他想起二维空间中的国际象棋同伴，回想起自己也活在2D世代的局限，心生怜悯。

那些骑士，永远被局限在8×8的棋盘之内厮杀，他们的世界永不改变。因此，林克去到阿卡来研究所寻求帮助，他得到新的道具——变形棋盘。

这个变形棋盘可以根据输入的两个参数的（p,q）创造全新的棋盘空间。

如下图分别是（p,q）为(3,9) , (6,3) ,以及(5,5)的棋盘空间。

image.png (./1535dce661.png)--image.png (./9a40274901.png)--image.png (./33abb03385.png)

假设2D世界的骑士，移动的方式按字母次序有如下8种：

image.png (./348369f95a.png)

请问对于每一种棋盘（p,q），2D骑士是否有一种一次遍历所有棋盘方格的路线？

如果有，请输出这条路线（若有多条路线，请输出字典序最小的路线）。

如果没有，请输出无。


输入
输入数据第一行为正整数n，代表有多少组输入样例

接下来n行是两个整数代表行p和列q, 代表变形棋盘的行列参数，其中（1 <= p * q <= 26）。


输出
每个样例的输出2行，格式如下：

"#i:" 其中i代表第i种棋盘

骑士跳过的每个格子（每个访问的格子用大写字母加数字表示），一条可行的路径输出如(A1B3C1A2B4C2A3B1C3A4B2C4)，

如果没有可行方案，则第二行输出：none


输入样例 1

5
5 1
5 2
5 3
5 4
5 5
输出样例 1

#1:
none
#2:
none
#3:
none
#4:
A1B3A5C4D2B1A3B5D4C2B4A2C1D3C5A4B2D1C3D5
#5:
A1B3A5C4A3B1D2E4C5A4B2D1C3B5D4E2C1A2B4D5E3C2E1D3E5
提示

Andy(2021)

Andy(2020)

来源

xmu

温馨提示

实在搞不定的话，你可以 点此下载测试数据 (./problem_4304_test_cases.zip)


*/

#include <iostream>
#include <vector>

#define mov_num 8

using namespace std;

typedef vector<short> hd_vec;

hd_vec Move[mov_num+1]= {{0,0},{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};

//bool Search_path(vector<hd_vec> &res,bool Board[],const short p,const short q,short x,short y)
bool Search_path(vector<hd_vec> &res,bool Board[],const short p,const short q,short x,short y)
{
    if((p>0)&&(q>0)&&(x>=0)&&(y>=0)&&(x<=q)&&(y<=p))
    {
        if((res.empty())&&(!x)&&(!y))
            for(bool *ptr_1=Board; ptr_1-Board<q; ++ptr_1)
                for(bool *ptr_2=ptr_1; ptr_2-Board<p*q; ptr_2+=q)
                {
                    x=(short)(ptr_1-Board+1),y=(short)((ptr_2-ptr_1)/q+1),(*Move)= {x,y};
                    *ptr_2=true,res.push_back((*Move));
                    bool flag=true;
                    for(bool *ptr=Board; ptr-Board<p*q; ++ptr)
                        if(!(*ptr))
                        {
                            flag=false;
                            break;
                        }
                    if(flag)
                        return flag;
                    else
                    {
                        if(Search_path(res,Board,p,q,x,y))
                            return true;
                        else
                            *ptr_2=false,res.pop_back();
                    }
                }
        else if((!res.empty())&&x&&y&&(*(Board+(y-1)*q+x-1)))
            for(short i=1; i<=mov_num; ++i)
            {
                x+=(Move[i])[0],y-=(Move[i])[1];
                if((x>0)&&(y>0)&&(x<=q)&&(y<=p))
                {
                    bool flag=true;
                    if(*(Board+(y-1)*(q)+x-1))
                    {
                        for(bool *ptr=Board; ptr-Board<p*q; ++ptr)
                            if(!(*ptr))
                            {
                                flag=false;
                                break;
                            }
                        if(flag)
                            return flag;
                    }
                    else
                    {
                        *(Board+(y-1)*(q)+x-1)=true,res.push_back({x,y});
                        if(Search_path(res,Board,p,q,x,y))
                            return true;
                        else
                            *(Board+(y-1)*(q)+x-1)=false,res.pop_back();
                    }
                }
                x-=(Move[i])[0],y+=(Move[i])[1];
//                bool flag=false;
//                switch(i)
//                {
//                case 1:
//                {
//                    if((x>2)&&(y>1))
//                        flag=true;
//                    break;
//                }
//                case 2:
//                {
//                    if((x>2)&&(y<p))
//                        flag=true;
//                    break;
//                }
//                case 3:
//                {
//                    if((x>1)&&(y>2))
//                        flag=true;
//                    break;
//                }
//                case 4:
//                {
//                    if((x>1)&&(y<p-1))
//                        flag=true;
//                    break;
//                }
//                case 5:
//                {
//                    if((x<q)&&(y>2))
//                        flag=true;
//                    break;
//                }
//                case 6:
//                {
//                    if((x<q)&&(y<p-1))
//                        flag=true;
//                    break;
//                }
//                case 7:
//                {
//                    if((x<q-1)&&(y>1))
//                        flag=true;
//                    break;
//                }
//                case 8:
//                {
//                    if((x<q-1)&&(y<p))
//                        flag=true;
//                    break;
//                }
//                default:
//                    break;
//                }
//                if(flag)
//                {
//                    x+=(Move[i])[0],y-=(Move[i])[1];
//                    if(*(Board+(y-1)*(q)+x-1))
//                    {
//                        for(bool *ptr=Board; ptr-Board<p*q; ++ptr)
//                            if(!(*ptr))
//                            {
//                                flag=false;
//                                break;
//                            }
//                        if(flag)
//                            return flag;
//                    }
//                    else
//                    {
//                        *(Board+(y-1)*(q)+x-1)=true,res.push_back({x,y});
//                        if(Search_path(res,Board,p,q,x,y))
//                            return true;
//                        else
//                            *(Board+(y-1)*(q)+x-1)=false,res.pop_back();
//                    }
//                    x-=(Move[i])[0],y+=(Move[i])[1];
//                }
            }
    }
    return false;
}

int main()
{
    long long n=0;
    cin>>n;
    for(long long i=0; i<n; ++i)
    {
        cout<<'#'<<i+1<<':'<<endl;
        short p=0,q=0;
        cin>>p>>q;
        bool Board[p][q];
        for(bool *ptr=*Board; ptr-*Board<p*q; ++ptr)
            *ptr=false;
        vector<hd_vec> ans;
        if(Search_path(ans,*Board,p,q,0,0))
        {
            for(auto &vec:ans)
                cout<<(char)(vec[0]-1+'A')<<vec[1];
            cout<<endl;
        }
        else
            cout<<"none"<<endl;
    }
    return 0;
}
