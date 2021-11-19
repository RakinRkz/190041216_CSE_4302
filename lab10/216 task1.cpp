#include <bits/stdc++.h>
using namespace std;

class Vehicle1
{
protected :
    int lic_no;
public :
    virtual void show_details ()
    {
        cout<<"License no: "<<lic_no<<'\n';
    }
};

class Bike1: public Vehicle1
{
public :
    Bike1(int n) 
    {
        lic_no = n;
    }
    // void show_details()
    // {
    //     cout<<"License no: "<<lic_no<<'\n';
    //     cout<<"Type: MotorBike(1)\n";
    // }
};

class Vehicle2
{
protected :
    int lic_no;
public :
    virtual void show_details() = 0;
};

class Bike2: public Vehicle2
{
public :
    Bike2(int n) 
    {
        lic_no = n;
    }
    void show_details ()
    {
        cout<<"License no: "<<lic_no<<'\n';
        cout<<"Type: MotorBike(2)\n";
    }
};

int main ()
{
    Bike1 b1(1235);

    b1.show_details();

    

    Bike2 b2(789653);

    b2.show_details();

}


