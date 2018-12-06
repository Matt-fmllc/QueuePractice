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

protected:
	CNode*	m_pRootNode;
	CNode*  m_pHeadNode;

	bool Recurse(CNode* _pNode, CNode* _pPrevNode, int* _pData);

public:
	CQueue(): m_pRootNode(nullptr) 
	{}
	virtual ~CQueue() {}


	virtual bool EnQueue(int* _pData);
	virtual bool DeQueue(int* _pData);
	virtual bool DeQueueRecursive(int* _pData);
};

class CQueue_Standard : public CQueue
{
private:
protected:
public:
	CQueue_Standard() {}
	~CQueue_Standard() {}
};

class CQueue_Priority : public CQueue
{
private:
protected:
public:
	CQueue_Priority() {}
	~CQueue_Priority() {}

	virtual bool EnQueue(int* _pData);
};

