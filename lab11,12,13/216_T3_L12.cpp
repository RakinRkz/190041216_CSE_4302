#include <bits/stdc++.h>
#include <process.h> //for exit()

using namespace std;

const int LIMIT = 10; //array size
////////////////////////////////////////////////////////////////

template<class T>
class safearay
{
private:
    T arr[LIMIT];
public:
    class OutOfBound
    {
    public:
        int val;
        OutOfBound(int v)
        {
            val=v;
        }
    };

    T& operator [](int n)
    {
        if( n< 0 || n>=LIMIT )
        {
            throw OutOfBound(n);
        }
        return arr[n];
    }
};

int main()
{

    try
    {
        safearay<int> sa1;
        for(int j=0; j<LIMIT+5; j++)
        {
            sa1[j] = j*2;
        }
        for(int j=0; j<LIMIT; j++)
        {
            int temp1 = sa1[j];
            cout << "Element " << j << " is " << temp1 << endl;
        }

    }
    catch(safearay<int>::OutOfBound err)
    {
        cout<<"Out of Bound at "<< err.val <<endl;
    }


    return 0;
}
