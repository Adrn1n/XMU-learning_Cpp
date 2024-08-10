#include <iostream>

using namespace std;

class Array_Out_Of_Range:public exception
{
public:
    const char *what() const noexcept override
    {
        return "Array index out of range!";
    }
};

template<typename T>
struct Node
{
    T A;
    Node *Next;
};

template<typename T>
class Array
{
    typedef Node<T> T_Node;

private:
    T_Node *Head,*Tail;

public:
    Array():Head(nullptr),Tail(nullptr)
    {
    }
    virtual ~Array()
    {
        while(Head)
        {
            T_Node *p=Head;
            Head=Head->Next;
            delete p;
        }
    }
    T_Node *Get_Head() const
    {
        return Head;
    }
    T_Node *Get_Tail() const
    {
        return Tail;
    }
    T_Node *Push(T a)
    {
        T_Node *p=new T_Node{a,nullptr};
        if(Tail)
        {
            Tail->Next=p;
            Tail=p;
        }
        else
            Head=Tail=p;
        return p;
    }
    T_Node *Pop(int n)
    {
        while((n--)&&(Head))
        {
            T_Node *p=Head;
            Head=Head->Next;
            delete p;
        }
        return Head;
    }
    T operator[](int n)
    {
        T_Node *p=Head;
        while((n>0)&&(p!=Tail))
        {
            p=p->Next;
            --n;
        }
        if(n)
            throw Array_Out_Of_Range();
        else
            return p->A;
    }
    int Print() const
    {
        int n=0;
        T_Node *p=Head;
        while(p!=Tail)
        {
            cout<<p->A<<' ';
            p=p->Next;
            ++n;
        }
        if(p)
            cout<<p->A<<endl;
        return n;
    }
};

int main()
{
    int n=0;
    cin>>n;
    Array<int> int_array_1;
    cout<<"ORG: "<<endl;
    while(n--)
    {
        int a=0;
        cin>>a;
        int_array_1.Push(a);
    }
    cout<<"N POP: "<<endl;
    int m=0;
    cin>>m;
    int_array_1.Pop(m);
    if(int_array_1.Get_Head())
    {
        int_array_1.Print();
        cout<<"Push a: "<<endl;
        int a=0;
        cin>>a;
        int_array_1.Push(a);
        int_array_1.Print();
        int T=0;
        cout<<"Times T: "<<endl;
        cin>>T;
        while(T--)
        {
            try
            {
                int i=0;
                cout<<"i: ";
                cin>>i;
                int a=int_array_1[i];
                cout<<"Array["<<i<<"]"<<": "<<a<<endl;
            }
            catch(Array_Out_Of_Range &error)
            {
                cerr<<"ERROR: "<<error.what()<<endl;
            }
        }
    }
    else
        cout<<"ERROR: Pop out of range!"<<endl;
    return 0;
}
