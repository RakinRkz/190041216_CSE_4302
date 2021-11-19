#include <bits/stdc++.h>
using namespace std;

class MyClass
{
private :
    int x;
public :
    MyClass () {}
    MyClass (int p) {
        x=p;
    }

    MyClass (MyClass &a)
    {
        x=a.x;
        cout<<"Copy initialized\n";
    }
    void show()
    {
         cout << x<<endl;
    }


   void operator = (MyClass &c)
    {
        x = c.x;
        cout << "assignment operator\n";
    }


};

int main ()
{
    MyClass c1(5);

    MyClass c2;
    c2=c1;

    MyClass c4=c1;
    c4.show();

    c2.show();

    MyClass b3(b2);
    c3.show();

}