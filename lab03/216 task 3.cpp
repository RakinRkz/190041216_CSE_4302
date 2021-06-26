#include<iostream>
#include<cstring>

using namespace std;

class Medicine
{
private:
    char brandName[50], genName[50];
    double discountPercent, unitPrice;
public:
    Medicine() : unitPrice(0), discountPercent(5) {}

    void assignName(char* name, char* genericName)
    {
         strcpy(brandName, name);
         strcpy(genName, genericName);
    }
    void assignPrice(double price)
    {
        unitPrice = price;
    }
    void setDiscountPercent(double percent)
    {
        if(percent > 45 || percent < 0)
        {
            cout<<"invalid discount percent.\n";
            return;
        }
        discountPercent = percent;
    }
    double getSellingPrice(int nos)
    {
        return 1.0*nos*(unitPrice - (unitPrice*discountPercent/100) );
    }
    void display()
    {
        printf("%s (%s) has a unit price BDT %0.2lf. Current discount %.0lf%%.\n", brandName, genName, unitPrice, discountPercent);
    }
};
int main()
{
    Medicine m1;
    m1.assignName("Napa", "Paracetamol");
    m1.assignPrice(1.50);
    m1.setDiscountPercent(20);
    m1.display();

    cout<<"Selling price of 10 units of m1: BDT "<<m1.getSellingPrice(10)<<".\n";

    return 0;
}
