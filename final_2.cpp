#include<bits/stdc++.h>
using namespace std;

class MyString
{
private:
	char* str;

public:
	MyString()
	{
		str = new char[1];
		str[0] = '\0';
	}

	MyString(char* s)
	{
		str = new char[strlen(s) + 1];

		strcpy(str, s);
	}

	MyString(MyString& ms)
	{
		str = new char[strlen(ms.str) + 1];

		strcpy(str, ms.str);
	}

	void assignString(char ar[])
	{
		str = new char[strlen(ar) + 1];

		strcpy(str, ar);
	}
	void getMS()
	{
		cout<<str<<endl;
	}
	int size()
	{
		return strlen(str);
	}
	~MyString()
	{
		delete str;
	}
};

int main()
{
	char* s = "rakin";
	MyString ms1(s);
	ms1.getMS();

	cout<<ms1.size()<<endl;


	char s2[6] = "hello";
	MyString ms2;
	ms2.assignString(s2);
	ms2.getMS();

	MyString ms3(ms2);
	ms3.getMS();
}
