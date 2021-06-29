#include<iostream>
#include<cmath>

using namespace std;

class Emp
{
private:
    string EmpName;
    int ID, Age;
    float Salary;
    void getStatus()
    {
        string st;
        if (Age <= 25)
        {
            if (Salary <= 20000)
                st = "Low";
            else
                st= "Moderate";
        }
        if (Age > 25)
        {
            if (Salary <= 21000)
                st = "Low";
            else if (Salary > 21000 && Salary < 60000)
                st = "Moderate";
            else
                st = "High";
        }
        cout << st << " Salaried Person";
    }
public:
    void FeedInfo(string n, int i, int a, float s)
    {
        EmpName = n;
        ID = i, Age = a,
    }

    void showInfo()
    {
        cout << EmpName << ' ' << ID << ' ' << age << ' ' << salary << '\n';
        getStatus();
    }
};

int main()
{
    Emp e1;
    e1.feedInfo("Abcd", 78, 29, 55000);
    e1.showInfo();

    return 0;
}
