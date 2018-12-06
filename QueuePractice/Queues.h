#pragma once

class CQueue
{
public:
	struct CNode {
		CNode* pNext;
		int* pData;

		CNode(): pNext(nullptr), pData(nullptr)
		{ }
		~CNode() 
		{ pNext = nullptr; pData = nullptr; }
	};

private:
	CNode*	m_pRootNode;
	CNode*  m_pHeadNode;

protected:
	bool Recurse(CNode* _pNode, CNode* _pPrevNode, int* _pData);

public:
	CQueue(): m_pRootNode(nullptr) 
	{}
	~CQueue() {}


	bool EnQueue(int* _pData);
	bool DeQueue(int* _pData);
	bool DeQueueRecursive(int* _pData);
};

