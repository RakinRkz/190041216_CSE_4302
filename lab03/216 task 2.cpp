#include<iostream>

using namespace std;

class RationalNumber
{
private:
    int p,q;
public:
    RationalNumber() : p(0), q(1) {}
    void Assign(int numerator, int denominator)
    {
        if(denominator == 0)
        {
            cout<<"error: cannot assign undefined value\n";
            return;
        }

        p = numerator, q = denominator;
    }
    double convert()
    {
        double x = 1.0*p/q;
        return x;
    }
    void invert()
    {
        if(p == 0)
        {
            cout<<"error: inverted value undefined\n";
            return;
        }
        swap(p, q);
    }
    void print()
    {
        cout<<p<<'/'<<q<<endl;
    }

};

int main()
{
    RationalNumber r1;

    r1.print();

    r1.invert();    //to show error
    r1.Assign(12, 0);   //to show error

    int p,q;
    cout<<"Nominator:";
    cin>>p;
    cout<<"denominator:";
    cin>>q;


    r1.Assign(p, q);
    r1.print();
    cout<<r1.convert()<<endl;

    r1.invert();
    r1.print();
    cout<<r1.convert()<<endl;

    return 0;
}
