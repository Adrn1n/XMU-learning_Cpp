#include <iostream>
#include <cstring>

using namespace std;

const short Labs_Num=4,Stations_in_Lab[Labs_Num]= {5,6,4,3},ID_Len=6;

class User
{
public:
    User(const char *id,bool is_new):Is_New(is_new)
    {
        strcpy(ID,id);
    }
    ~User() {}
    bool Print_ID()
    {
        cout<<(this->ID);
        return true;
    }
    bool operator==(const User &usr)
    {
        return !(strcmp(ID,usr.ID));
    }

private:
    char ID[ID_Len+1] {0};
    const bool Is_New;

    friend class ComputerLab;
};

struct loginReq
{
    User* userPointer;
    int labNum;
    int stationNum;
    bool flag;
};

struct logoffReq
{
    User* userPointer;
    bool flag;
};

class ComputerLab
{
public:
    ComputerLab(short lab_num,short station_num):Lab_Num(lab_num),Station_Num(station_num),Station_User(new User*[station_num]()) {}
    ~ComputerLab()
    {
        if(Station_User)
        {
            for(User **p = this->Station_User; (p-(this->Station_User))<(this->Station_Num); ++p)
                if(*p&&((*p)->Is_New))
                    delete *p;
            delete []Station_User;
        }
    }
    User **Find_User(const User &usr)
    {
        for(User **p=this->Station_User; (p-(this->Station_User))<(this->Station_Num); ++p)
            if(*p&&(**p==usr))
                return p;
        return nullptr;
    }
    void operator+(loginReq &r)
    {
        User **p=Station_User;
        p+=(r.stationNum-1);
        if(*p)
            r.flag=false;
        else
            *p=r.userPointer;
    }
    void operator-(logoffReq &r)
    {
        User **p=Find_User(*r.userPointer);
        if(p)
        {
            r.flag=true;
            if((*p)->Is_New)
                delete *p;
            *p=nullptr;
        }
        else
            r.flag=false;
    }
    short Print_Lab_State()
    {
        cout<<this->Lab_Num<<' ';
        short i;
        for(User **p=(this->Station_User); (i=(short)(p-(this->Station_User)))<(this->Station_Num); p++)
        {
            cout<<i+1<<": ";
            if(*p)
                (*p)->Print_ID();
            else
                cout<<"empty";
            cout<<' ';
        }
        cout<<endl;
        return i;
    }

private:
    const short Lab_Num,Station_Num;
    User **Station_User;
};

int main()
{
    ComputerLab Labs[Labs_Num]= {ComputerLab(1,Stations_in_Lab[0]),ComputerLab(2,Stations_in_Lab[1]),ComputerLab(3,Stations_in_Lab[2]),ComputerLab(4,Stations_in_Lab[3])};
    char op=0;
    while(cin>>op,op!='=')
    {
        char usr_id[ID_Len+1]= {0};
        cin>>usr_id;
        User *usr_ptr=new User(usr_id,true);
        switch(op)
        {
        case '+':
        {
            short req_lab_num=0,req_station_num=0;
            cin>>req_lab_num>>req_station_num;
            loginReq login_req= {usr_ptr,(int)req_lab_num,(int)req_station_num,true};
            for(ComputerLab *p=Labs; p-Labs<Labs_Num; ++p)
                if(!(login_req.flag=!(p->Find_User(*usr_ptr))))
                    break;
            if(login_req.flag)
                Labs[req_lab_num-1]+login_req;
            if(!login_req.flag)
                cout<<"invalid login"<<endl,delete usr_ptr;
            break;
        }
        case '-':
        {
            logoffReq logoff_req= {usr_ptr,false};
            for(ComputerLab *p=Labs; p-Labs<Labs_Num; ++p)
            {
                *p-logoff_req;
                if(logoff_req.flag)
                    break;
            }
            if(!logoff_req.flag)
                cout<<"invalid logoff"<<endl,delete usr_ptr;
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
