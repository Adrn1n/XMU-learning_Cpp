#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const short Days_In_Year=365,Days_In_Month[12]= {31,28,31,30,31,30,31,31,30,31,30,31},Labs_Num=4,Stations_In_Lab[Labs_Num]= {3,4,5,6},ID_Len_Stu=6,ID_Len_Sta=7,Days1_Stu=14,Days1_Sta=30,Price_Day1_Stu=0,Price_Day1_Sta=2,Price_Day2_Stu=1,Price_Day2_Sta=4;

struct Date
{
    short Day,Month,Year;
};

inline bool Is_Leap_Year(const short year)
{
    return (((!(year%4))&&(year%100))||!(year%400));
}

inline short Day_Num_In_Year(const Date *date)
{
    short num=date->Day;
    for(const short *p=Days_In_Month; p-Days_In_Month<(date->Month-1); ++p)
        num+=*p;
    if((date->Month>2)&&(Is_Leap_Year(date->Year)))
        num++;
    return num;
}

inline int Leap_Year_Between_Years(const Date *day_start,const Date *day_end)
{
    int num=(day_end->Year-day_start->Year)/4;
    if((day_start->Year%4)>(day_end->Year%4))
        num++;
    num-=(day_end->Year-day_start->Year)/100;
    if((day_start->Year%100)>(day_end->Year%100))
        num--;
    num+=(day_end->Year-day_start->Year)/400;
    if((day_start->Year%400)>(day_end->Year%400))
        num++;
    return num;
}

inline int Day_Num_Between_Days(const Date *day_start,const Date *day_end)
{
    int num=Days_In_Year*(day_end->Year-day_start->Year);
    num+=Leap_Year_Between_Years(day_start,day_end);
    if(Is_Leap_Year(day_start->Year))
        num++;
    if(Is_Leap_Year(day_end->Year))
        num--;
    num-=Day_Num_In_Year(day_start),num+=Day_Num_In_Year(day_end);
    return num;
}

class User;

struct LoginReq
{
    User* userPointer;
    int labNum;
    int stationNum;
    Date day;
    bool flag;
};

struct LogoffReq
{
    User* userPointer;
    Date day;
    bool flag;
};

class User
{
public:
    User():ID(nullptr),Login_Req(nullptr),Logoff_Req(nullptr),Days(0),Money(0)
    {}
    virtual ~User()
    {
        delete Login_Req;
        delete Logoff_Req;
        delete[] ID;
    }
    char *Print_ID() const
    {
        if(ID)
            cout<<ID;
        return ID;
    }
    bool operator==(const char *usr_id)
    {
        return !strcmp(ID,usr_id);
    }
    LoginReq *Add_Login_Req(LoginReq *login_req)
    {
        Login_Req=login_req;
        return Login_Req;
    }
    LogoffReq *Add_Logoff_Req(LogoffReq *logoff_req)
    {
        Logoff_Req=logoff_req;
        return Logoff_Req;
    }
    bool Print_Login_Date() const
    {
        if(Login_Req)
        {
            printf("%02hd/%02hd/%hd",Login_Req->day.Day,Login_Req->day.Month,Login_Req->day.Year);
            return true;
        }
        else
            return false;
    }
    int Days_Used()
    {
        if(Login_Req&&Logoff_Req)
            Days+=Day_Num_Between_Days(&Login_Req->day,&Logoff_Req->day);
        return Days;
    }
    int Print_Days() const
    {
        cout<<Days;
        return Days;
    }
    virtual int Pay()=0;
    int Print_Money() const
    {
        cout<<Money;
        return Money;
    }

protected:
    char*ID;
    LoginReq *Login_Req;
    LogoffReq *Logoff_Req;
    int Days,Money;

    friend class ComputerLab;
};

class Student:public User
{
public:
    Student(const char *id)
    {
        ID=new char[ID_Len_Stu+1];
        strcpy(ID,id);
    }
    virtual ~Student()
    {}
    int Pay()
    {
        Days_Used();
        Money+=Days*Price_Day1_Stu;
        if((Days-Days1_Stu)>0)
            Money+=(Days-Days1_Stu)*(Price_Day2_Stu-Price_Day1_Stu);
        return Money;
    }

    friend class ComputerLab;
};

class Staff:public User
{
public:
    Staff(const char *id)
    {
        ID=new char[ID_Len_Sta+1];
        strcpy(ID,id);
    }
    virtual ~Staff()
    {}
    int Pay()
    {
        Days_Used();
        Money+=Days*Price_Day1_Sta;
        if((Days-Days1_Sta)>0)
            Money+=(Days-Days1_Sta)*(Price_Day2_Sta-Price_Day1_Sta);
        return Money;
    }

    friend class ComputerLab;
};

class ComputerLab
{
public:
    ComputerLab(const short lab_num,const short station_num):Lab_Num(lab_num),Station_Num(station_num),Usr(new User *[station_num]())
    {}
    virtual ~ComputerLab()
    {
        if(Usr)
        {
            for(User **p=Usr; (p-Usr)<Station_Num; ++p)
                delete *p;
        }
        delete[] Usr;
    }
    User **Find_User(const char *usr_id) const
    {
        for(User **p=Usr; (p-Usr)<Station_Num; ++p)
            if(*p&&(**p==usr_id))
                return p;
        return nullptr;
    }
    void operator+(LoginReq &r)
    {
        if((r.labNum!=Lab_Num)||(r.stationNum>Station_Num))
            r.flag=false;
        else
        {
            User **p=Usr;
            p+=(r.stationNum-1);
            if(*p)
                r.flag=false;
            else
            {
                r.userPointer->Add_Login_Req(&r);
                *p=r.userPointer;
                r.flag=true;
            }
        }
    }
    void operator-(LogoffReq &r)
    {
        User **p=Find_User(r.userPointer->ID);
        if(p)
        {
            r.userPointer->Add_Logoff_Req(&r);
            r.userPointer->Pay();
            *p=nullptr;
            r.flag=true;
        }
        else
            r.flag=false;
    }
    short Print_Lab_State() const
    {
        cout<<Lab_Num<<' ';
        short i;
        for(User **p=Usr; (i=(short)(p-Usr))<Station_Num; ++p)
        {
            cout<<i+1<<": ";
            if(*p)
            {
                (*p)->Print_ID();
                cout<<' ';
                (*p)->Print_Login_Date();
            }
            else
                cout<<"empty";
            cout<<' ';
        }
        cout<<endl;
        return i;
    }

private:
    short const Lab_Num,Station_Num;
    User **Usr;
};

int main()
{
    ComputerLab Labs[Labs_Num]= {ComputerLab(1,Stations_In_Lab[0]),ComputerLab(2,Stations_In_Lab[1]),ComputerLab(3,Stations_In_Lab[2]),ComputerLab(4,Stations_In_Lab[3])};
    char op=0;
    while(cin>>op,op!='=')
    {
        char usr_id[ID_Len_Sta+1]= {0};
        cin>>usr_id;
        User *usr_ptr=nullptr;
        switch(op)
        {
        case '+':
        {
            LoginReq *login_req_ptr=new LoginReq{nullptr,0,0,{0},true};
            cin>>login_req_ptr->labNum>>login_req_ptr->stationNum;
            scanf("%hd/%hd/%hd",&(login_req_ptr->day.Day),&(login_req_ptr->day.Month),&(login_req_ptr->day.Year));
            if((login_req_ptr->labNum<=0)||(login_req_ptr->labNum>Labs_Num)||(login_req_ptr->stationNum<=0)||(login_req_ptr->stationNum>Stations_In_Lab[login_req_ptr->labNum-1]))
                login_req_ptr->flag=false;
            else
            {
                for(ComputerLab *p=Labs; p-Labs<Labs_Num; ++p)
                    if(p->Find_User(usr_id))
                    {
                        login_req_ptr->flag=false;
                        break;
                    }
                if(login_req_ptr->flag)
                {
                    if((*usr_id>='0')&&(*usr_id<='9'))
                        usr_ptr=new Staff(usr_id);
                    else
                        usr_ptr=new Student(usr_id);
                    login_req_ptr->userPointer=usr_ptr;
                    Labs[login_req_ptr->labNum-1]+*login_req_ptr;
                }
            }
            if(!login_req_ptr->flag)
            {
                delete login_req_ptr;
                delete usr_ptr;
                cout<<"invalid login"<<endl;
            }
            break;
        }
        case '-':
        {
            LogoffReq *logoff_req_ptr=new LogoffReq{};
            scanf("%hd/%hd/%hd",&(logoff_req_ptr->day.Day),&(logoff_req_ptr->day.Month),&(logoff_req_ptr->day.Year));
            for(ComputerLab *p=Labs; p-Labs<Labs_Num; ++p)
            {
                User **usr_ptr_ptr=p->Find_User(usr_id);
                if(usr_ptr_ptr)
                {
                    usr_ptr=*usr_ptr_ptr;
                    logoff_req_ptr->userPointer=usr_ptr;
                    *p-*logoff_req_ptr;
                    break;
                }
            }
            if(logoff_req_ptr->flag)
            {
                logoff_req_ptr->userPointer->Print_ID();
                cout<<" log off, time: ";
                logoff_req_ptr->userPointer->Print_Days();
                cout<<" days, price: ";
                logoff_req_ptr->userPointer->Print_Money();
                cout<<" RMB"<<endl;
                delete usr_ptr;
            }
            else
            {
                delete logoff_req_ptr;
                cout<<"invalid logoff"<<endl;
            }
            break;
        }
        default:
            break;
        }
        for(ComputerLab *p=Labs; p-Labs<Labs_Num; ++p)
            p->Print_Lab_State();
        cout<<endl;
    }
    return 0;
}
