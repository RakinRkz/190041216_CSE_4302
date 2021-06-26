#include<iostream>

using namespace std;

class Counter
{
private:
    int cnt, step;

public:
    Counter() : cnt(0){}

    void setIncrementStep(int step_val)
    {
        step = step_val;
    }
    int getCount()
    {
        return cnt;
    }
    void increment()
    {
        cnt += step;
    }
    void resetCount()
    {
        cnt = 0;
    }
};
int main()
{
    Counter c1;
    cout<<c1.getCount()<<endl;

    c1.setIncrementStep(2);
    c1.increment();
    cout<<c1.getCount()<<endl;

    c1.resetCount();
    cout<<c1.getCount()<<endl;

    c1.setIncrementStep(5);
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.increment();
    cout<<c1.getCount()<<endl;

    return 0;
}
