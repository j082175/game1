#include <iostream>
#include <vector>
#include "Person.h"
#include <functional>
#include <assert.h>
//

#include <time.h>
#include "SinglyLinkedListEx.h"
#include "Stack.h"
#include "Tree.h"

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

int Factorial(const int& num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * Factorial(num - 1);
}

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
	CTree<int, int> ct;
	
	
}