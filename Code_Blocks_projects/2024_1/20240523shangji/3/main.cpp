#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
bool Quick_Sort(const typename vector<T>::iterator Start,const typename vector<T>::iterator End)
{
    typedef typename vector<T>::iterator It_Type;
    if(Start>=End)
        return false;
    else
    {
        T pivot=Start[0];
        bool flag=true;
        for(It_Type it=Start; End-it>0; ++it)
            if(it[0]!=pivot)
            {
                if(it[0]<pivot)
                    pivot=it[0];
                flag=false;
                break;
            }
        if(flag)
            return true;
        else
        {
            It_Type Partition_Point=partition(Start,End,[pivot](const T &a)->bool{return a<=pivot;});
            Quick_Sort<int>(Start,Partition_Point);
            Quick_Sort<int>(Partition_Point,End);
            return true;
        }
    }
}

int main()
{
    vector<int> Arr;
    int n=0;
    cin>>n;
    cout<<"ORG: "<<endl;
    while(n--)
    {
        int a=0;
        cin>>a;
        Arr.push_back(a);
    }
    vector<int>::iterator Start=Arr.begin(),End=Arr.end();
    n=(int)(Arr.size());
    Quick_Sort<int>(Start,End);
    cout<<endl<<"RES: "<<endl;
    for(vector<int>::iterator it=Arr.begin(); it-Start<n; ++it)
        cout<<it[0]<<' ';
    cout<<endl;
    return 0;
}
