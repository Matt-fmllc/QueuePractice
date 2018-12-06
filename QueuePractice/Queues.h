#pragma once

class CQueue
{
public:
	struct CNode {
		CNode* pNext;
		void* pData;

		CNode(): pNext(nullptr), pData(nullptr)
		{ }
		~CNode() 
		{ pNext = nullptr; pData = nullptr; }
	};

private:
	CNode*	m_pRootNode;

protected:
public:
	CQueue(): m_pRootNode(nullptr) 
	{}
	~CQueue() {}


	bool EnQueue(void* _pData);
	bool DeQueue(void* _pData);
};

