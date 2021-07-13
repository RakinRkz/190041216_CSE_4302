#include<bits/stdc++.h>
using namespace std;

class Float{
private:
    float x;
public:
    Float(float f=0):x(f){}

    float operator + (const Float f){
        return (x+f.x);
    }
    float operator - (const Float f){
        return (x-f.x);
    }
    float operator * (const Float f){
        return(x*f.x);
    }
    float operator / (const Float f){
        return (x/f.x);
    }
    void display(){cout << x << '\n';}
    ~Float(){}
};
int main()
{
    Float f1(2.5),f2(3.1);
    f1.display();
    f2.display();

    cout << (f1+f2) << ' ';
    cout << (f1-f2)<< ' ';
    cout << (f1*f2)<< ' ';
    cout << (f1/f2)<< ' ';
}
