/*
星期几
描述

hbc 惜字如金，喜欢用0，1，2，3，4，5，6来代替星期：Sunday，Monday，Tuesday，Wednesday，Thursday，Friday，Saturday。所以你问他今天是星期几，如果今天是星期一，他会说：1。现在给定星期信息，你需要判定 hbc 说出的正确数字。如果星期信息有误，那么输出-1。


输入
输入的第一行为一个整数t （1≤t≤10000），代表一共有t 组输入。

接下来的t 行，每行一个字符串s，代表星期信息,s 的长度小于 20。


输出
输出t 行，如果是正确的星期信息，那么输出对应的数字。否则输出-1。


输入样例 1

3
Tuesday
Wednesday
year
输出样例 1

2
3
-1
*/

#include <iostream>
#include <cstring>

using namespace std;

#define N 20
#define N_name_day 9
#define N_day_in_week 7

typedef struct tag_Day_num
{
    const char day[N_name_day+1];
    const short num;
} Day_num;

//const char Sun[]="Sunday";
//const char Mon[]="Monday";
//const char Tue[]="Tuesday";
//const char Wed[]="Wednesday";
//const char Thu[]="Thursday";
//const char Fri[]="Friday";
//const char Sat[]="Saturday";

int main()
{
    const Day_num day_table[N_day_in_week]= {{"Sunday",0},{"Monday",1},{"Tuesday",2},{"Wednesday",3},{"Thursday",4},{"Friday",5},{"Saturday",6}};
    int t=0;
    cin>>t;
    while(t--)
    {
        char S[N+1]= {0};
        cin>>S;
        bool flag=true;
//        if(!(strcmp(S,Sun)))
//            cout<<"0"<<endl;
//        else if(!(strcmp(S,Mon)))
//            cout<<"1"<<endl;
//        else if(!(strcmp(S,Tue)))
//            cout<<"2"<<endl;
//        else if(!(strcmp(S,Wed)))
//            cout<<"3"<<endl;
//        else if(!(strcmp(S,Thu)))
//            cout<<"4"<<endl;
//        else if(!(strcmp(S,Fri)))
//            cout<<"5"<<endl;
//        else if(!(strcmp(S,Sat)))
//            cout<<"6"<<endl;
//        else
//            cout<<"-1"<<endl;
        for(const Day_num *p=day_table; p-day_table<N_day_in_week; p++)
            if(!(strcmp(S,p->day)))
            {
                flag=false;
                cout<<p->num<<endl;
                break;
            }
        if(flag)
            cout<<-1<<endl;
    }
    return 0;
}
