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
public:
	CQueue(): m_pRootNode(nullptr) 
	{}
	~CQueue() {}


	bool EnQueue(int* _pData);
	bool DeQueue(int* _pData);
};

