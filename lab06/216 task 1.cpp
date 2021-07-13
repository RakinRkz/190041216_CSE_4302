#include<iostream>

using namespace std;

class Counter
{
private:
    int cnt, step;

public:
    Counter(int c=0, int s=1) : cnt(c), step(s){}

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
    Counter operator + (const Counter c2)
    {
    return Counter(cnt + c2.cnt, min(step, c2.step));
    }

    friend Counter operator + (int x, Counter);

    Counter operator + (int x)
    {
        return Counter(cnt+x, step);
    }

    Counter operator ++()
    {
        return Counter(++cnt, step);
    }
    Counter operator ++(int)
    {
        return Counter(cnt++, step);
    }

};

Counter operator + (int x, Counter c2)
{
    return Counter(x+c2.cnt, c2.step);
}


int main()
{
    Counter c1, c2(2,2), c3(3,4);

    cout<<c1.getCount()<<endl;

    c1 = c2+c3;
    cout<<c1.getCount()<<endl;

    c1.increment();
    cout<<c1.getCount()<<endl;


    return 0;
}
