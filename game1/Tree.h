#pragma once
#include <assert.h>

enum NODE_INSERT_TYPE
{
	NIT_SIBLING,
	NIT_CHILD
};

template<typename Key, typename Value>
class CTreeNode
{
	template<typename Key, typename Value>
	friend class CTree;
private:
	CTreeNode()
		:m_pSibling(nullptr),m_pChild(nullptr)
	{}
	~CTreeNode() {}
private:
	CTreeNode<Key, Value>* m_pSibling;
	CTreeNode<Key, Value>* m_pChild;
	Key m_Key;
	Value m_Value;

};

template<typename Key, typename Value>
class CTree
{
	typedef CTreeNode<Key, Value> NODE;
	typedef CTreeNode<Key, Value>* PNODE;

	PNODE m_pRoot;
	int m_iSize;
public:
	CTree()
		:m_pRoot(nullptr),m_iSize(0)
	{}

	void Insert(const Key& key,const Value& value,const Key& BaseKey = Key(),
		NODE_INSERT_TYPE eType = NIT_SIBLING)
	{

		PNODE pNode = new NODE;

		pNode->m_Key = key;
		pNode->m_Value = value;

		if (!m_pRoot)
		{
			m_pRoot = pNode;
			++m_iSize;
		}
		else
		{
			PNODE pBaseNode = FindNode(BaseKey, m_pRoot);

			if (!pBaseNode)
			{
				delete pNode;
				return;
			}

			else if (pBaseNode == m_pRoot && eType == NIT_SIBLING)
			{
				delete pNode;
				return;
			}

			switch (eType)
			{
			case NIT_SIBLING:
				if (!pBaseNode->m_pSibling)
				{
					pBaseNode->m_pSibling = pNode;
				}
				else
				{
					PNODE pSibling = pBaseNode->m_pSibling;

					pNode->m_pSibling = pSibling;
					pBaseNode->m_pSibling = pNode;

				}
				break;
			case NIT_CHILD:
				if (!pBaseNode->m_pChild)
				{
					pBaseNode->m_pChild = pNode;
				}
				else
				{
					PNODE pChild = pBaseNode->m_pChild;

					pNode->m_pSibling = pChild;
					pBaseNode->m_pSibling = pNode;

				}
				break;
			default:
				break;
			}

			++m_iSize;
		}
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	int size()const
	{
		return m_iSize;
	}

private:
	PNODE FindNode(const Key& key ,PNODE pNode)
	{
		PNODE pResult = nullptr;

		if (pNode->m_Key == key)
		{
			return pNode;
		}

		if (pNode->m_pSibling)
		{
			pResult = FindNode(key, pNode->m_pSibling);
		}

		if (pNode->m_pChild && !pResult)
		{
			pResult = FindNode(key, pNode->m_pChild);
		}

		return pResult;
	}
};