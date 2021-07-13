#include<iostream>
#include<cmath>
using namespace std;

class Coordinate
{
private:
    float x,y;
public:
    Coordinate(float x=0, float y=0):x(x), y(y){}
    ~Coordinate()
    {
        //cout<<"Dtor called\n";
    }
    void display()
    {
        cout<<"x = "<<x<<"\ny= "<<y<<'\n';
    }

    float getDistance(Coordinate c)
    {
        return sqrt(pow(x-c.x, 2) + pow(y-c.y, 2));
    }
    float getDistance()
    {
        return getDistance(Coordinate(0,0));
    }
    void move_x(float d){x+=d;}
    void move_y(float d){y+=d;}
    void move(float d){
        move_x(d);
        move_y(d);
    }

    float dist(Coordinate a, Coordinate b)
    {
        return sqrt(pow(a.x-b.x, 2) + pow(a.x-b.y, 2));
    }
    Coordinate operator ++()
    {
        return Coordinate(++x, ++y);
    }
    Coordinate operator ++(int)
    {
        return Coordinate(x++, y++);
    }
    Coordinate operator --()
    {
        return Coordinate(--x, --y);
    }
    Coordinate operator --(int)
    {
        return Coordinate(x--, y--);
    }

    bool operator == (const Coordinate c)
    {
        Coordinate tmp(x,y);
        Coordinate o(0,0);
        return dist(tmp,o) == dist(c,o);
    }
    bool operator != (const Coordinate c)
    {
        Coordinate tmp(x,y), o(0,0);
        return dist(tmp,o) != dist(c,o);
    }
    bool operator <= (const Coordinate c)
    {
        Coordinate tmp(x,y), o(0,0);
        return dist(tmp,o) <= dist(c,o);
    }
    bool operator >= (const Coordinate c)
    {
        Coordinate tmp(x,y), o(0,0);
        return dist(tmp,o) >= dist(c,o);
    }
    bool operator < (const Coordinate c)
    {
        Coordinate tmp(x,y), o(0,0);
        return dist(tmp,o) < dist(c,o);
    }
    bool operator > (const Coordinate c)
    {
        Coordinate tmp(x,y), o(0,0);
        return dist(tmp,o) > dist(c,o);
    }
};




int main()
{
    Coordinate c1(1.3, 1.6), c2(2.5, 3.7), c3(1,1), c4(-1,-1);
    cout<<(c3==c4)<<'\n';

    c3++;
    cout<<(c3==c4)<<'\n';
    c3--;
    cout<<(c3==c4)<<'\n';

    cout<< (c1<c2) <<'\n';

    cout<<(c2>c3)<<'\n';


    return 0;
}
