#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node;

template<typename T>
class Iterator
{
	template<typename T>
	friend class SinglyLinkedList;

private:
	Node<T>* mNode;
public:
	Iterator()
		:mNode(nullptr)
	{}

	bool operator==(const Iterator& iter)
	{
		return mNode == iter.mNode;
	}

	bool operator!=(const Iterator& iter)
	{
		return mNode != iter.mNode;
	}

	T& operator*()
	{
		return mNode->mData;
	}

	void operator++()
	{
		mNode = mNode->mFront;
	}

	void operator++(int)
	{
		mNode = mNode->mFront;
	}

	void operator--()
	{
		mNode = mNode->mRear;
	}

	void operator--(int)
	{
		mNode = mNode->mRear;
	}
};

template<typename T>
class Node
{
	template<typename T>
	friend class Iterator;

	template<typename T>
	friend class SinglyLinkedList;

private:
	T mData;
	Node<T>* mFront;
	Node<T>* mRear;

public:
	Node()
		:mData(0), mFront(nullptr), mRear(nullptr)
	{}
	~Node()
	{}
};

template<typename T>
class SinglyLinkedList
{
private:
	Node<T>* mBegin;
	Node<T>* mEnd;
	int mCount;

	typedef Iterator<T> iterator;

public:
	SinglyLinkedList()
		:mCount(0)
	{
		mBegin = new Node<T>;
		mEnd = new Node<T>;

		mBegin->mFront = mEnd;
		mEnd->mRear = mBegin;
		mBegin->mRear = nullptr;
		mEnd->mFront = nullptr;
	}
	~SinglyLinkedList()
	{
		clear();
		delete mBegin;
		delete mEnd;
	}

	void push_back(const T& data)
	{
		Node<T>* dataNode = new Node<T>;

		Node<T>* extraNode = mEnd->mRear;

		extraNode->mFront = dataNode;
		dataNode->mRear = extraNode;

		dataNode->mFront = mEnd;
		mEnd->mRear = dataNode;

		dataNode->mData = data;

		mCount++;
	}

	void push_front(const T& data)
	{
		Node<T>* dataNode = new Node<T>;
		Node<T>* extraNode = mBegin->mFront; // mBegin 과 extra 사이에 넣는것이 목적
		dataNode->mData = data;
		mBegin->mFront = dataNode;
		dataNode->mFront = extraNode;
		extraNode->mRear = dataNode;
		dataNode->mRear = mBegin;
		mCount++;
	}

	int count()const
	{
		return mCount;
	}

	T pop_back()
	{
		if (mCount == 0)
		{
			assert(false);
		}
		Node<T>* outNode = mEnd->mRear;
		Node<T>* backNode = outNode->mRear;
		T data = outNode->mData;
		delete outNode;
		mCount--;

		backNode->mFront = mEnd;
		mEnd->mRear = backNode;

		return data;
	}

	T pop_front()
	{
		if (mCount == 0)
		{
			assert(false);
		}
		Node<T>* outNode = mBegin->mFront;
		Node<T>* nextNode = outNode->mFront;
		T data = outNode->mData;
		delete outNode;
		mCount--;
		mBegin->mFront = nextNode;
		nextNode->mRear = mBegin;
		return data;
	}

	void clear()
	{
		Node<T>* nodeOne = mBegin->mFront;
		while (nodeOne != mEnd)
		{
			Node<T>* nodeTwo = nodeOne->mFront;
			delete nodeOne;
			nodeOne = nodeTwo;
		}

		mBegin->mFront = mEnd;
		mEnd->mRear = mBegin;

		mCount = 0;
	}

	void print()
	{
		Node<T>* node = mBegin->mFront;
		while (node != mEnd)
		{
			cout << node->mData << endl;
			node = node->mFront;
		}
	}

	Iterator<T> begin()
	{
		Iterator<T> iter;
		iter.mNode = mBegin->mFront;
		return iter;
	}

	Iterator<T> end()
	{
		Iterator<T> iter;
		iter.mNode = mEnd;
		return iter;
	}

	void sort(bool(*fptr)(const T&, const T&))
	{
		for (Node<T>* first = mBegin->mFront; first != mEnd->mRear; first = first->mFront)
		{
			for (Node<T>* second = first->mFront; second != mEnd; second = second->mFront)
			{
				if (fptr(first->mData, second->mData))
				{
					T data = first->mData;
					first->mData = second->mData;
					second->mData = data;
				}
			}
		}
	}
};
