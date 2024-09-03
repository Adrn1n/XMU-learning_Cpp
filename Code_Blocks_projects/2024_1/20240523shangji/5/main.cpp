#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const short ID_Len=14,Subject_N=8;

class Student
{
private:
    string ID;
    string Name;
    double Grades[Subject_N] {0};
    double Avg;

public:
    Student(string id,string name):ID(id),Name(name),Avg(0)
    {
    }
    virtual ~Student()
    {
    }
    double *Fetch_Grades()
    {
        for(double *p=Grades; p-Grades<Subject_N; ++p)
            cin>>*p;
        Cal_Avg();
        return Grades;
    }
    string Print_ID() const
    {
        cout<<ID;
        return ID;
    }
    string Print_Name() const
    {
        cout<<Name;
        return Name;
    }
    double Print_Avg() const
    {
        cout<<Avg;
        return Avg;
    }
    bool Print() const
    {
        this->Print_ID();
        cout<<' ';
        this->Print_Name();
        cout<<": ";
        this->Print_Avg();
        cout<<endl;
        return true;
    }
    double Get_Avg() const
    {
        return Avg;
    }
    double Cal_Avg()
    {
        for(double *p=Grades; p-Grades<Subject_N; ++p)
            Avg+=*p;
        Avg/=Subject_N;
        return Avg;
    }
    static bool Cmp(Student &stu_1,Student &stu_2)
    {
        double avg_1=stu_1.Get_Avg(),avg_2=stu_2.Get_Avg();
        return avg_1<avg_2;
    }
};

int main()
{
    vector<Student> Students;
    char id[ID_Len+1]= {0};
    cout<<"ORG: "<<endl;
    while((scanf("%s",id))!=EOF)
    {
        string name;
        cin>>name;
        Students.emplace_back(id,name);
        Students.back().Fetch_Grades();
    }
    const vector<Student>::iterator Start=Students.begin(),End=Students.end();
    sort(Start,End,Student::Cmp);
    cout<<endl<<"RES: "<<endl;
    for_each(Start,End,[](const Student &stu)->bool{stu.Print(); return true;});
    return 0;
}
