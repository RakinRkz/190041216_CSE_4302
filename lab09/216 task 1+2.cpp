#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
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
    void setMadeof(Material val)
    {
        madeof=val;
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
            return string("");
    }
    virtual void productDetails()=0;
    void display()
    {
        cout << "Regular Price: " << price <<endl;
        cout << "Discounted Price: " << discount <<endl;
        cout << "Material: " << getMadeof() << endl;
    }
};

enum class BedSize {Single,SemiDouble,Double};

class Bed: public Furniture
{
private:
    BedSize bsize;
public:
    Bed(double p,double d,Material m,BedSize s):Furniture(p,d,m)
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
    Sofa(double p,double d,Material m,SeatNumber s):Furniture(p,d,m)
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
    DiningTable(double p,double d,Material m,ChairCount c):
        Furniture(p,d,m)
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

int main()
{
    Furniture* f_list[100];
/**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,9877,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,1234,Material::Steel,SeatNumber::Five);
    f_list[2] = new DiningTable(13000,3345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed(10090,4423,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

    */

    for(int i=0;i<4;i++)
        f_list[i]->productDetails();


}
