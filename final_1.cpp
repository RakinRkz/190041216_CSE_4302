#include<bits/stdc++.h>
using namespace std;

class Animal
{
private:
	string name;
	int age;
public:
	virtual void identifyingCharacteristics() = 0;
};

class Mammal : public Animal
{
public:
	void identifyingCharacteristics()
	{
		cout<<"This is a mammal\n";
	}
};

class Amphibian : public Animal
{
public:
	void identifyingCharacteristics()
	{
		cout<<"This is an amphibian\n";
	}
};
