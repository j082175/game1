#pragma once
//선입 후출 first in last out
#include <assert.h>

template<typename T>
class CStackNode
{
	template<typename T>
	friend class CStackList;

private:
	CStackNode<T>* m_pNext;
	T mData;

	CStackNode()
		:m_pNext(nullptr)
	{
		mData = 0;
	}

	~CStackNode()
	{}
};

template<typename T>
class CStackList
{
	typedef CStackNode<T>* PNODE;
	typedef CStackNode<T> NODE;

	PNODE m_pNode;
	int m_iSize;
public:
	CStackList()
		:m_pNode(nullptr),m_iSize(0)
	{
		m_pNode = new NODE;
	}

	void push(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->mData = data;

		pNode->m_pNext = m_pNode;
		m_pNode = pNode;

		++m_iSize;
	}

	T pop()
	{
		if (m_iSize == 0)
			assert(false);
		PNODE pNext = m_pNode->m_pNext;
		T data = m_pNode->mData;
		delete m_pNode;
		m_pNode = pNext;
		m_iSize--;
		return data;

	}

	int count() const
	{
		return m_iSize;
	}


};

