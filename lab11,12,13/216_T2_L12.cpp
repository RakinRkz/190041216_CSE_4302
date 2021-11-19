
#include <bits/stdc++.h>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 11; //array size
////////////////////////////////////////////////////////////////
template <class Type>
Type amax (Type* arr, int sz)
{
    Type temp=arr[0];
    for (int i=0;i<sz;i++)
    {
        if (arr[i]>temp) temp=arr[i];
    }
    return temp;
}

int main ()
{
    int ar1[LIMIT];

    for (int i=0;i<LIMIT;i++)
    {
        ar1[i]=i*5;
    }

     for (int i=0;i<LIMIT;i++)
    {
        cout<<ar1[i]<<endl;
    }

    cout<<"The largest element is "<<amax(ar1, LIMIT)<<endl<<endl;

    double ar2[LIMIT];

    for (int i=0;i<LIMIT;i++)
    {
        ar2[i]=(double)i*0.5;
    }

    for (int i=0;i<LIMIT;i++)
    {
        cout<<ar2[i]<<endl;
    }

    cout<<"The largest element is "<<amax(ar2, LIMIT)<<endl;

}
