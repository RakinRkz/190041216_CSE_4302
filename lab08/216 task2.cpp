#include <iostream>
#include<iomanip>
using namespace std;

class Staff         ///staff class
{
private:
    int code;
    string name;
public:
    void whoAmI()
    {
        cout << "- staff\n";
    }
    void setName_Code(string n, int c)     ///sets name and code of staff
    {
        code=c;
        name=n;
    }
    void displayname(){
        cout<<name<<'\t';
    }
    void displaycode(){
        cout<<code<<'\t';
    }
};

class Teacher : public Staff    ///teacher class, inherits from staff
{
private:
    string subject;
    string publication;
public:
    Teacher(string n,int c,string sub,string pub): subject(sub),publication(pub) ///setting sub and pub using init list
    {
		setName_Code(n, c);     ///setting name and code at staff
    }

    void whoAmI()
    {
        cout<<"I am a teacher";
        Staff::whoAmI();
    }

    void display()
    {
        cout<<"About Teacher :\n";
        printf("name\tcode\tsubject\t\t\tpublication\n");
        displayname();
        displaycode();
        cout<<subject<<'\t'<<publication<<"\n\n";
    }
};

class Officer : public Staff        ///officer class, inherits from staff
{
private:
    string grade;
public:
    Officer(string n,int c,string g): grade(g) ///setting grade using init list
    {
		setName_Code(n, c);    ///setting name and code at staff
    }
    void whoAmI()
    {
        cout << "I am a officer ";
        Staff::whoAmI();
    }
    void display()
    {
        cout << "About officer:\n";
        printf("name\t\tcode\tCategory\n");
        displayname();
        displaycode();

        cout << grade << "\n\n";
    }
};

class Typist : public Staff             ///typist class, inherits from staff
{
private:
    double speed;
    unsigned int wage;
public:
    void setSpeed_Wage(double s,unsigned int w)
    {
    	speed = s;
    	wage = w;
    }

    void whoAmI()
    {
        cout<<"- typist";
        Staff::whoAmI();
    }
    void displayspeed()
    {
        cout<<fixed<<setprecision(6)<<speed<<'\t';
    }
    void displaywage()
    {
        cout<<wage<<'\n';
    }
};

class RegularTypist : public Typist        ///regular typist class, inherits from typist
{
public:
    RegularTypist(string n,int c,double sp,unsigned int wg)
    {
        setName_Code(n, c);         ///setting name and code at staff
        setSpeed_Wage(sp, wg);
    }
    void whoAmI()
    {
        cout<<"I am a regular ";
        Typist::whoAmI();
    }
    void display()
    {
        cout<<"About regular typist :\n";
        printf("name\t\tcode\tspeed\t\twage\n");
        displayname();
        displaycode();
        displayspeed();
        displaywage();
        cout << "\n\n";
    }
};

class CasualTypist : public Typist          ///casual typist class, inherits from typist
{
unsigned int dailyWages;
public:
    CasualTypist(string n,int c,double sp,unsigned int wg,unsigned int dWg): dailyWages(dWg)
    {
        setName_Code(n, c);     ///setting name and code at staff
        setSpeed_Wage(sp,wg);
    }
    void whoAmI()
    {
        cout<<"I am a casual ";
        Typist::whoAmI();
    }
    void display()
    {
        cout <<"About casual typist :\n";
        printf("name\t\tcode\tspeed\t\twage\n");
        displayname();
        displaycode();
        displayspeed();
        displaywage();
    }
};


int main()
{
    Teacher t1("Ataur",420,"programming with C++","Tata McGraw Hill");      ///declaring and inputing teacher data
    t1.whoAmI();
    t1.display();

    Officer o1("Md. Rashed",222,"First Class");     ///declaring and inputing officer data
    o1.whoAmI();
    o1.display();

    RegularTypist r("Rabiul Awal",333,85.5,15000);      ///declaring and inputting regular typist data
    r.whoAmI();
    r.display();

    CasualTypist c("Kawser Ahmed",333,78.900002,10000,1000);    ///declaring and inputting casual typist data
    c.whoAmI();
    c.display();

    return 0;
}


