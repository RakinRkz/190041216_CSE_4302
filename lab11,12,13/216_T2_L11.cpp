#include<bits/stdc++.h>
#include<fstream>
#include <fstream>                //for file-stream functions
#include <iostream>
#include <typeinfo>               //for typeid()
#include <process.h>

using namespace std;

enum shape_type {tsquare, tcircle};

class Shape
{
private:
    int x, y;
    string name;
    static int n;
    static Shape* arrap[];


public:
    virtual void setData()
    {
        cout << " Enter Shape Name: ";
        cin >> name ;
        cout << " Enter Shape Coordinates: \n x = ";
        cin >> x;
        cout<<" y = ";
        cin>>y;

    }
    virtual void getData()
    {
        cout<<". I am "<<name<<" and my Coordinates : x = "<<x<<", y = "<<y<<endl;
    }
    virtual string type()
    {
        return name;
    }
    virtual shape_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};

int Shape::n; //current number of employees
Shape* Shape::arrap[100];


class Circle: public Shape
{
private:
    double radius;
public:
    void setData()
    {
        Shape::setData();
        cout << " Enter radius: ";
        cin >> radius;
    }
    void getData()
    {
        Shape::getData();
        cout << "I am a circle. My radius: " << radius;
    }
};

class Square: public Shape
{
private:
    int length;
public:
    void setData()
    {
        Shape::setData();
        cout << " Enter Length: ";
        cin >> length;
    }
    void getData()
    {
        Shape::getData();
        cout << "I am a Square. My length: " << length;
    }
};

void Shape::add()
{
    char ch;
    cout << "'c' to add a circle"
         "\n's' to add a square"
         "\nEnter selection: ";
    cin >> ch;
    if(ch=='c')
    {
        arrap[n] = new Circle;
    }
    else if(ch=='s')
    {
        arrap[n] = new Square;
    }
    else
    {
        cout << "\nUnknown shape type\n";
        return;
    }
    arrap[n++]->setData();
}

void Shape::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1);

        arrap[j]->getData();
        cout << endl;
    }
}

shape_type Shape::get_type()
{
    if( typeid(*this) == typeid(Square) )
        return tsquare;
    else if( typeid(*this)==typeid(Circle) )
        return tcircle;
    else
    {
        cerr << "\nBad shape type";
        exit(1);
    }
    return tcircle;
}

void Shape::write()
{
    int size;
    cout << "Writing " << n << " Shapes.\n";
    ofstream ouf;
    shape_type shtype;
    ouf.open("Shapes.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        shtype = arrap[j]->get_type();
        //write type to file
        ouf.write( (char*)&shtype, sizeof(shtype) );
        switch(shtype)                     //find its size
        {
        case tsquare:
            size=sizeof(Square);
            break;
        case tcircle:
            size=sizeof(Circle);
            break;
        }
        ouf.write( (char*)(arrap[j]), size );
        if(!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }

    }

}


void Shape::read()
{
    int size;
    ifstream inf; //open ifstream in binary
    shape_type shtype;
    inf.open("Shapes.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        inf.read( (char*)&shtype, sizeof(shtype) );
        if( inf.eof() )
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch(shtype)
        {
        //make new employee
        case tcircle:                    //of correct type
            arrap[n] = new Circle;
            size=sizeof(Circle);
            break;
        case tsquare:
            arrap[n] = new Square;
            size=sizeof(Square);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }

        inf.read( (char*)arrap[n], size );
        if(!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " Shapes\n";
}



int main()
{
    char ch;
    while(true)
    {
        cout << "\n'a' -- add data "
             "\n'd' -- display data"
             "\n'w' -- write all data to file"
             "\n'r' -- read all  data from file"
             "\n'x' -- exit"
             "\nEnter selection: ";
        cin >> ch;
        if(ch=='a')
        {
            Shape::add();
        }
        else if(ch=='d')
        {
            Shape::display();
        }else if(ch=='r')
        {
            Shape::read();
        }else if(ch=='w')
        {
            Shape::write();
        }
        else if(ch=='x')
        {
            exit(0);
        }
        else{
            cout<<"Unknown Command"<<endl;
        }

    }
    return 0;
}
