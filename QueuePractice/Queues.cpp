

#include "pch.h"
#include "Queues.h"

bool CQueue::EnQueue(int* _pData)
{
	CNode* pNewNode = new CNode;
	if (!pNewNode)
		return false;

	pNewNode->pData = _pData;
	if (!m_pRootNode) {
		pNewNode->pNext = nullptr;
		m_pRootNode = pNewNode;
	}
	else {
		pNewNode->pNext = m_pRootNode;
		m_pRootNode = pNewNode;
	}
		
	return true;
}
bool CQueue::DeQueue(int* _pData)
{
	CNode* pNode = m_pRootNode;
	CNode* pLastNode = nullptr;

	while (pNode) {
		if (pNode->pNext != nullptr) {
			pLastNode = pNode;
			pNode = pNode->pNext;
		}
		else {
			*_pData = *pNode->pData;
			// now remove this node
			if (m_pRootNode == pNode) {
				m_pRootNode = nullptr;
			}
			else {
				pLastNode->pNext = nullptr;
			}
			delete(pNode);
			return true;
		}
	}

	return false;
}

bool CQueue::Recurse(CNode* _pNode, CNode* _pPrevNode, int* _pData)
{
	if (_pNode->pNext != nullptr) {
		Recurse(_pNode->pNext, _pNode, _pData);
	}
	else {
		*_pData = *_pNode->pData;
		if (_pPrevNode) {
			_pPrevNode->pNext = nullptr;
		}
		else {
			m_pRootNode = nullptr;
		}
		delete(_pNode);
		return true;
	}

	return false;
}

bool CQueue::DeQueueRecursive(int* _pData)
{

	if (!m_pRootNode) {
		// empty q
		return false;
	}

	CNode* pNode = m_pRootNode;
	Recurse(pNode, nullptr, _pData);

	return true;
}

bool CQueue_Priority::EnQueue(int* _pData)
{
	CNode* pNode = m_pRootNode;
	CNode* pPrevNode = m_pRootNode;
	CNode* pNewNode = new CNode;
	if (!pNewNode)
		return false;
	
	pNewNode->pData = _pData;

	while (pNode != nullptr) {
		if (*pNewNode->pData <= *pNode->pData) {
			pNewNode->pNext = pNode;
			if (pNode == m_pRootNode) {
				m_pRootNode = pNewNode;
			}
			else {
				pPrevNode->pNext = pNewNode;
			}
			return true;
		}
		else if (pNode->pNext == nullptr) {
			pNode->pNext = pNewNode;
			pNewNode->pNext = nullptr;
			return true;
		}
		else {
			pPrevNode = pNode;
			pNode = pNode->pNext;
		}
	}

	// null case
	pNewNode->pNext = nullptr;
	m_pRootNode = pNewNode;

	return true;
}