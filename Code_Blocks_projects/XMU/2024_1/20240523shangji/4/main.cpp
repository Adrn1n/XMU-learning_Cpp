#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n=0,a=0,s=0;
    cin>>n;
    vector<int> Arr;
    while(n--)
    {
        int b=0;
        cin>>b;
        Arr.push_back(b);
    }
    cin>>a;
    for_each(Arr.begin(),Arr.end(),[a,&s](int b)->bool{if(b>a)
{
    s+=b;
    return true;
}
else return false;});
    cout<<s<<endl;
    return 0;
}
