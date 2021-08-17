#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    string name;
    double price;
    double discount;
    Material madeof;
public:

    Furniture(string n,double p,double d,Material m):name(""),price(0),discount(0),madeof(Material::Wood)
    {
        setName(n);
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setName(string n)
    {
        name=n;
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material m)
    {
        madeof=m;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("Foam");
    }
    double getDP()
    {
        return discount;
    }

    virtual void productDetails()=0;
//    friend void order(Furniture &f1,Furniture &f2);
    void display()
    {
        cout << "Product Name: " << name;
        cout << "\nRegular Price: " << price;
        cout << "\nDiscounted Price: " << discount;
        cout << "\nMaterial: " << getMadeof() << '\n';
    }
};

enum class BedSize {Single,SemiDouble,Double};
class Bed:public Furniture
{
private:
    BedSize bsize;
public:
    Bed(string n,double p,double d,Material m,BedSize s):Furniture(n,p,d,m)
    {
        setSize(s);
    }
    void setSize(BedSize val)
    {
        bsize=val;
    }
    string getSize()
    {
        if(bsize==BedSize::Single) return string("Single");
        else if(bsize==BedSize::SemiDouble) return string("Semi-Double");
        else return string("Double");
    }
    void productDetails()
    {
        display();
        cout << "Bed Size: " << getSize() << "\n\n";
    }
};

enum class SeatNumber{One,Two,Three,Four,Five};
class Sofa:public Furniture
{
private:
    SeatNumber seat;
public:
    Sofa(string n,double p,double d,Material m,SeatNumber s):Furniture(n,p,d,m)
    {
        setNumber(s);
    }
    void setNumber(SeatNumber val){seat=val;}
    string getSeatNumber()
    {
        if(seat==SeatNumber::One) return string("One");
        else if(seat==SeatNumber::Two) return string("Two");
        else if(seat==SeatNumber::Three) return string("Three");
        else if(seat==SeatNumber::Four) return string("Four");
        else return string("Five");
    }
    void productDetails()
    {
        display();
        cout << "Seat Number: " << getSeatNumber() << "\n\n";
    }
};

enum class ChairCount{Two,Four,Six};
class DiningTable:public Furniture
{
private:
    ChairCount chair;
public:
    DiningTable(string n,double p,double d,Material m,ChairCount c):
        Furniture(n,p,d,m)
        {
            setCount(c);
        }
    void setCount(ChairCount val){chair=val;}
    string getChairCount()
    {
        if(chair==ChairCount::Two) return string("Two");
        else if(chair==ChairCount::Four) return string("Four");
        else return string("Six");
    }
    void productDetails()
    {
        display();
        cout << "Chair Count: " << getChairCount() << "\n\n";
    }
};

void swap_f(Furniture **f1,Furniture **f2)
{
    if((*f1)->getDP() > (*f2)->getDP()){
        Furniture *temp=*f1;
        *f1=*f2;
        *f2=temp;
    }
}

void sort_furniture_price(Furniture** f,int n)
{
    for(int j=0;j<n-1;j++)
        for(int k=j+1;k<n;k++)
            swap_f(f+j,f+k);
}

int main()
{
    void bsort(Furniture**,int);
    Furniture* f_list[100];

    f_list[0] = new Bed("Bed",10000,9877,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa("Sofa",11000,1234,Material::Steel,SeatNumber::Five);
    f_list[2] = new DiningTable("Dining Table",13000,3345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed("Bed",10090,4423,Material::Wood,BedSize::Single);

    for(int i=0;i<4;i++)
        f_list[i]->productDetails();

    sort_furniture_price(f_list,4);
    cout<<"After sorting:\n";

    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

}




