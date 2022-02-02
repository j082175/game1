#include <iostream>
#include <vector>
#include "Person.h"
#include <functional>

//
#include "LinkedList.h"
#include <time.h>

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

struct _tagData
{
	int iData;
	char cName[20];
};

bool DataSort(const _tagData& tSrc, const _tagData& tDest)
{
	return tSrc.iData > tDest.iData;
}

int main()
{
	
	CLinkedList<int> sl;
	for (int i = 0; i < 100; i++)
	{
		sl.push_back(i);
	}
	cout << sl.size();

	CLinkedList<int>::iterator iter;
	for (iter = sl.begin(); iter != sl.end(); iter++)
	{
		cout << *iter << endl;
	}

	CLinkedList<int>::reverse_iterator rIter;
	for (rIter = sl.rbegin(); rIter != sl.rend(); rIter++)
	{
		cout << *rIter << endl;
	}

	CLinkedList<_tagData> dataList;

	srand((unsigned int)time(0));

	cout << "-------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		_tagData tData{};
		tData.iData = rand() % 100;

		dataList.push_back(tData);

		cout << tData.iData << endl;
	}

	dataList.sort(DataSort);

	CLinkedList<_tagData>::iterator iterD;
	
	for (iterD = dataList.begin(); iterD != dataList.end(); iterD++)
	{
		cout << (*iterD).iData << endl;
	}
}