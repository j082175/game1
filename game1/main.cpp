#include <iostream>
#include <vector>
#include "Person.h"
#include <functional>
#include <assert.h>
//

#include <time.h>
#include "SinglyLinkedListEx.h"

using namespace std;

//class A
//{
//	char* strA;
//public:
//	A(const char* str)
//	{
//		strA = new char[strlen(str) + 1];
//	}
//
//	virtual ~A()
//	{
//		cout << "~A" << endl;
//		delete[] strA;
//	}
//};
//
//class B : public A
//{
//	char* strB;
//public:
//	B(const char* str1,const char* str2)
//		:A(str1)
//	{
//		strB = new char[strlen(str2) + 1];
//	}
//
//	~B()
//	{
//		cout << "~B" << endl;
//		delete[] strB;
//	}
//};



struct _data
{
	int mData;
	std::string mString;
};

bool sort(const _data& lhs, const _data& rhs)
{
	return lhs.mData < rhs.mData;
}

int main()
{
	SinglyLinkedList<_data> sl;

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 10; i++)
	{
		_data data{};
		data.mData = rand() % 100;
		sl.push_back(data);
		cout << data.mData << endl;
	}

	sl.sort(sort);

	cout << "---------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << sl.pop_back().mData << endl;
	}
}