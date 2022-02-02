#pragma once
#include <assert.h>
template<typename T>
class CListIterator;
template<typename T>
class CListReverseIterator;

template<typename T>
class CListNode
{
	CListNode()
		:m_Data(0)
	{ m_pNext = nullptr; m_pPrev = nullptr; }
	~CListNode() {}
public://
	T m_Data;
	CListNode<T>* m_pNext; // 앞노드
	CListNode<T>* m_pPrev; // 뒤노드

	template<typename T>
	friend class CLinkedList;

	template<typename T>
	friend class CListIterator;

	template<typename T>
	friend class CListReverseIterator;
};

template<typename T>
class CLinkedList
{
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;
	typedef CListReverseIterator<T> reverse_iterator;

public:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_iSize;
public:
	CLinkedList()
		:m_iSize(0)
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

public:
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pNext = m_pBegin->m_pNext;
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;

		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		if (m_pEnd->m_pPrev == nullptr)
		{
			assert(false);
		}
		PNODE deleteNode = m_pEnd->m_pPrev;
		PNODE beforeNode = deleteNode->m_pPrev;

		beforeNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = beforeNode;

		delete deleteNode;
		m_iSize--;
	}

	void pop_front()
	{
		if (empty())
		{
			assert(false);
		}
		PNODE deleteNode = m_pBegin->m_pNext;
		PNODE frontNode = deleteNode->m_pNext;

		frontNode->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = frontNode;
		
		delete deleteNode;
		m_iSize--;
	}

	T getFront()const
	{
		if (empty())
		{
			assert(false);
		}
		PNODE getNode = m_pBegin->m_pNext;
		return getNode->m_Data;
	}

	T getBack()const
	{
		if (empty())
		{
			assert(false);
		}
		return m_pEnd->m_pPrev->m_Data;
	}

	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;
		while (pNode != m_pEnd)
		{
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}

		m_iSize = 0;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size() const
	{
		return m_iSize;
	}

	bool empty()const
	{
		return m_iSize == 0;
	}

	iterator begin()const
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end()const
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	reverse_iterator rbegin()const
	{
		reverse_iterator rIter;
		rIter.m_pNode = m_pEnd->m_pPrev;
		return rIter;
	}

	reverse_iterator rend()const
	{
		reverse_iterator rIter;
		rIter.m_pNode = m_pBegin;
		return rIter;
	}

	void sort(bool(*pFunc)(const T&, const T&))
	{
		for (PNODE pFirst = m_pBegin->m_pNext; pFirst != m_pEnd->m_pPrev; pFirst = pFirst->m_pNext)
		{
			for (PNODE pSecond = pFirst->m_pNext; pSecond != m_pEnd; pSecond = pSecond->m_pNext)
			{
				if (pFunc(pFirst->m_Data, pSecond->m_Data))
				{
					T temp = pFirst->m_Data;
					pFirst->m_Data = pSecond->m_Data;
					pSecond->m_Data = temp;
				}
			}
		}
	}
};

template<typename T>
class CListIterator
{
	template<typename T>
	friend class CLinkedList;
public:
	CListIterator()
	{
		m_pNode = nullptr;
	}
	~CListIterator(){}

private:
	typedef CListNode<T>* PNODE;
	PNODE m_pNode;

public:
	bool operator==(const CListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator!=(const CListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator++()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator++(int)
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator--()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator--(int)
	{
		m_pNode = m_pNode->m_pPrev;
	}

	T& operator*()
	{
		return m_pNode->m_Data;
	}
};

template<typename T>
class CListReverseIterator
{
	template<typename T>
	friend class CLinkedList;
public:
	CListReverseIterator()
	{
		m_pNode = nullptr;
	}
	~CListReverseIterator() {}

private:
	typedef CListNode<T>* PNODE;
	PNODE m_pNode;

public:
	bool operator==(const CListReverseIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator!=(const CListReverseIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator++()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator++(int)
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator--()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator--(int)
	{
		m_pNode = m_pNode->m_pNext;
	}

	T& operator*()
	{
		return m_pNode->m_Data;
	}
};