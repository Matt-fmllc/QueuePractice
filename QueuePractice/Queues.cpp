

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