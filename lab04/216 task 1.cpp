#include<iostream>
using namespace std;

class BankAccount
{
private:
    int acc_num;
    string holder_name, acc_type;
    float curr_balance, min_balance;

public:
    BankAccount(int num, string name, string typ, float b, float mb ):
        {
            acc_num = num;
            holder_name = name;
            acc_type = typ;
            curr_balance = b;
            min_balance = mb;

        }
    ~BankAccount()
    {
        cout<<"Account of Mr. "<<holder_name<<" with account no "<<
        acc_num<<" is destroyed with a balance BDT "<<curr_balance<<'\n';
    }
    void show()
    {
        cout<<"Account number: "<<acc_num<<'\n';
        cout<<"Account holder name: "<<holder_name<<'\n';
        cout<<"Account type: "<<acc_type<<'\n';
        cout<<"Current balance: "<<curr_balance<<'\n';
        cout<<"Minimum balance: "<<min_balance<<'\n';
    }

    void showBalance()
    {
        cout<<"Current balance: "<<curr_balance<<'\n';
    }
    void deposit(float money)
    {
        curr_balance += money;
    }

    void withdrawal(float money)
    {
        if(curr_balance - money >= min_balance)
            curr_balance -= money;
        else
            cout<<"Not enough balance\n";
    }

    void giveInterest(float rate = 3)
    {
        float in = curr_balance*rate/100;
        in -= in/10;
        curr_balance += in;
    }

};

int main()
{

    BankAccount b1(101, "rakin", "Savings", 1000, 100);


    b1.show();

    return 0;
}
