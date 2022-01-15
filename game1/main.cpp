#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class A
{
	char* strA;
public:
	A(const char* str)
	{
		strA = new char[strlen(str) + 1];
	}

	virtual ~A()
	{
		cout << "~A" << endl;
		delete[] strA;
	}
};

class B : public A
{
	char* strB;
public:
	B(const char* str1,const char* str2)
		:A(str1)
	{
		strB = new char[strlen(str2) + 1];
	}

	~B()
	{
		cout << "~B" << endl;
		delete[] strB;
	}
};

int main()
{
	vector<shared_ptr<Animal>> vec;
	vec.resize(10);
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = make_shared<Person>(Person(i));
		//vec.push_back(make_shared<Person>(Person(i)));
	}
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].get()->getIdNum();
		vec[i].get()->getInfo();
	}

	auto ani = make_shared<Person>(Person(1));
	auto ani2 = shared_ptr<Person>(new Person(22));

	shared_ptr<Animal> const ani3 = make_shared<Person>(Person(3));
	shared_ptr<const Animal> ani4 = make_shared<Person>(Person(4));
	const Animal* ani5 = new Person(44);
	ani5->bark();
	(*ani4).bark();
	ani3->bark();

	std::cout << (*ani4)[1];
	(*ani4)[0] = 1;
	//std::cout << (*ani2)[0];
}