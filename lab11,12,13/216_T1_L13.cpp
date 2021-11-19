#include <bits/stdc++.h>

using namespace std;
const int LIMIT = 11; //array size
int main ()
{
    set <int> st;
    int arr[6];

    for (int i=0, j=0;i<LIMIT;i+=2, j++)
    {
       arr[j] = i;
    }
    cout<<"the array: ";
    for(auto it:arr)
        cout<<it<<' ';



    for (int i=1;i<LIMIT;i+=2)
    {
       st.insert(i);
    }

    cout<<"\nthe set: ";
    for(auto it:st)
        cout<<it<<' ';


    vector <int> vct_merged(LIMIT);
    merge(arr, arr+6, st.begin(), st.end(), vct_merged.begin());

    cout<<"\n Merged: \n";

    for (int i=0;i<vct_merged.size();i++)
    {
     cout<<vct_merged[i]<<" ";
    }

}
