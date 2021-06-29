#include<iostream>
#include<cmath>
using namespace std;

class Rectangle
{
private:
    float length, width;
public:
    Rectangle(float l = 1, float w = 1): length(l), width(w){}

    void perimeter()
    {
        cout<<"Perimeter = "<<2*(length + width)<<'\n';
    }
    void area()
    {
        cout<<"Area = "<<(length*width)<<'\n';
    }
    void diagonal()
    {
        cout<<"Diagonal = "<<sqrt(length*length + width*width)<<'\n';
    }
    void angle()
    {
        cout<<"Angle between diagonal and a length = "<<atan(length/width)*180/3.1416<<" degrees\n";
    }
    void Set(float l, float w)
    {
        if(l<1.0 || l>20.0)
            cout<<"length error\n";
        else
            length = l;

        if(w<1.0 || w>20.0)
            cout<<"width error\n";
        else
            width = w;
    }

    void get()
    {
        cout<<"Length: "<<length<<"\nWidth: "<<width<<'\n';
    }
};

int main()
{
    Rectangle r1(10, 20);

    r1.perimeter();

    r1.angle();

    return 0;
}
