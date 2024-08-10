#include <iostream>
#include <string>

using namespace std;

bool If_Swap(const void* const a,const void* const b)
{
    return (*((int *)a)>*(int *)b);
}

char *Selection_Sort_1(void* const Arr,void* const End,const int Elem_Size,bool (*If_Swap)(const void* const,const void* const))
{
    char* const Base=(char *)Arr,*End_Char=(char *)End;
    for(char *p=Base; p!=End_Char-Elem_Size; p+=Elem_Size)
        for(char *q=p+Elem_Size; q!=End_Char; q+=Elem_Size)
        {
            if(If_Swap(p,q))
            {
                char tmp[Elem_Size]= {0};
                memcpy(tmp,p,Elem_Size);
                memcpy(p,q,Elem_Size);
                memcpy(q,tmp,Elem_Size);
            }
        }
    return Base;
}

template<typename T>
T *Selection_Sort_2(T* const Arr,T* const End)
{
    for(T *p=Arr; p!=End-1; ++p)
        for(T *q=p+1; q!=End; ++q)
            if(If_Swap(p,q))
            {
                T tmp=*p;
                *p=*q;
                *q=tmp;
            }
    return Arr;
}

int main()
{
    int n=0;
    cin>>n;
    int A[n]= {0};
    cout<<"ORG: "<<endl;
    for(int *p=A; p-A<n; ++p)
        cin>>*p;
    cout<<"RES: "<<endl;
//    Selection_Sort_1(A,&A[n],sizeof(int),If_Swap);
    Selection_Sort_2(A,&A[n]);
    for(int *p=A; p-A<n; ++p)
        cout<<*p<<' ';
    cout<<endl;
    return 0;
}
