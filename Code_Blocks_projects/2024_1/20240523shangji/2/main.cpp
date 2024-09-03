#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T A;
    Node *Next;
};

template<typename T>
class Queue
{
    typedef Node<T> Node_Tag;

private:
    Node_Tag *Head,*Tail;

public:
    Queue():Head(nullptr),Tail(nullptr)
    {
    }
    virtual ~Queue()
    {
        while(Head)
        {
            Node_Tag *p=Head;
            Head=Head->Next;
            delete p;
        }
    }
    Node_Tag *Get_Head() const
    {
        return Head;
    }
    Node_Tag *Get_Tail() const
    {
        return Tail;
    }
    Node_Tag *Push(T a)
    {
        Node_Tag *p=new Node_Tag{a,nullptr};
        if(Tail)
        {
            Tail->Next=p;
            Tail=p;
        }
        else
            Head=Tail=p;
        return p;
    }
    Node_Tag *Pop(int n)
    {
        while(n--)
        {
            Node_Tag *p=Head;
            if(Head)
            {
                Head=Head->Next;
                delete p;
            }
            else
                break;
        }
        return Head;
    }
    int Print() const
    {
        int n=0;
        Node_Tag *p=Head;
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
    Queue<int> int_queue_1;
    cout<<"ORG: "<<endl;
    while(n--)
    {
        int a=0;
        cin>>a;
        int_queue_1.Push(a);
    }
    cout<<"N POP: "<<endl;
    int m=0;
    cin>>m;
    int_queue_1.Pop(m);
    int_queue_1.Print();
    cout<<"Push a: "<<endl;
    int a=0;
    cin>>a;
    int_queue_1.Push(a);
    int_queue_1.Print();
    return 0;
}
