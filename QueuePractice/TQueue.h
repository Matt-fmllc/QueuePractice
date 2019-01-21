#pragma once

#include <cassert>

namespace QueueTemplate{

	template<class T>
	class TQueue
	{
	public:
		// defines behavior of Queue
		typedef enum _QueueTypes
		{
			eQT_Illegal,

			eQT_SingleLinked,
			eQT_DoubleLinked,
			eQT_Circular,
			eQT_Priority,
			
			eQT_Mex
		}QueueType;

		// defines memory handling types
		typedef enum _AllocationType
		{
			eAT_Illegal,

			eAT_FixedMem,
			eAT_DynamicMem,

			eAT_Max,
		}AllocationType;

	private:
		template<class T>
		class TNode
		{
		public:
			T			Data;
			TNode<T>*	pNext;
			TNode<T>*	pPrev;

			TNode(const T& data) noexcept :
				Data(data), pNext(nullptr), pPrev(nullptr)
			{
			}
			~TNode() {}
		};


		TNode<T>*		m_pRoot;
		TNode<T>*		m_pHead;

		int				m_iAllocationSize;
		AllocationType	m_eAllocType;

		QueueType		m_eQueueType;

	protected:
		inline virtual bool Clr_SL_DynMem();
		inline virtual bool EnQ_SL_DynMem(const T& NewItem);
		inline virtual bool EnQ_SL_DynMem2(const T& NewItem);	// 1 ptr implementation
		inline virtual bool DeQ_SL_DynMem(T& ReturnItem);
		inline virtual bool DeQ_SL_DynMem2(T& ReturnItem);		// 1 ptr implementation

		inline virtual bool EnQ_DL_DynMem(const T& NewItem);
		inline virtual bool DeQ_DL_DynMem(T& ReturnItem);

	public:
		TQueue() noexcept :
			m_pRoot(nullptr), 
			m_pHead(nullptr), 
			m_iAllocationSize(-1), 
			m_eAllocType(eAT_DynamicMem), 
			m_eQueueType(eQT_SingleLinked)
		{

		}
		TQueue(QueueType _eQT, AllocationType _eAllocType, int _iAllocSize);

		virtual ~TQueue();

		inline virtual bool EnQueue(const T& NewItem);
		inline virtual bool DeQueue(T& ReturnItem);
		inline virtual bool Search(const T& SearchItem);

		inline virtual bool Clear();
	};

	template<class T>
	TQueue<T>::TQueue(QueueType _eQT, AllocationType _eAllocType, int _iAllocSize) :
		m_pRoot(nullptr),
		m_pHead(nullptr),
		m_iAllocationSize(_iAllocSize),
		m_eAllocType(_eAllocType),
		m_eQueueType(_eQT)
	{
		switch (_eQT) {
		case eQT_DoubleLinked:
			if (_eAllocType == eAT_DynamicMem) {

			}
			else if (_eAllocType == eAT_FixedMem) {

			}
			break;
		case eQT_SingleLinked:
			if (_eAllocType == eAT_DynamicMem) {

			}
			else if (_eAllocType == eAT_FixedMem) {

			}
			break;
		default:
			assert(0 && "Unhandled Q Type");
		}
	}

	template<class T>
	TQueue<T>::~TQueue()
	{
		switch (m_eAllocType) {
		case eAT_DynamicMem:
			Clr_SL_DynMem();
			break;
		case eAT_FixedMem:
			break;
		default:
			assert(0 && "Unknown Memory allocation type");
		}
	}

	template<class T>
	bool TQueue<T>::EnQ_DL_DynMem(const T& NewItem)
	{
		TNode<T>* pNewNode = new TNode<T>(NewItem);
		assert(pNewNode);

		if (m_pHead == nullptr) {
			m_pHead = pNewNode;
			m_pRoot = pNewNode;
		}
		else {
			m_pHead->pNext = pNewNode;
			pNewNode->pPrev = m_pHead;
			m_pHead = m_pHead->pNext;
		}

		return true;
	}

	template<class T>
	bool TQueue<T>::DeQ_DL_DynMem(T& ReturnItem)
	{
		TNode<T>* pTemp = m_pRoot;
		if (pTemp == nullptr) {
			return false;
		}

		m_pRoot = m_pRoot->pNext;
		if (m_pRoot != nullptr) {
			m_pRoot->pPrev = nullptr;
		}
		else {
			m_pRoot = nullptr;
			m_pHead = nullptr;
		}
		return true;
	}

	template<class T>
	bool TQueue<T>::EnQ_SL_DynMem2(const T& NewItem)
	{
		TNode<T>* pNewNode = new TNode<T>(NewItem);
		assert(pNewNode);

		pNewNode->pNext = m_pRoot;
		m_pRoot = pNewNode;

		if (m_pHead == nullptr) {
			m_pHead = pNewNode;
		}
		
		return true;
	}

	template<class T>
	bool TQueue<T>::EnQ_SL_DynMem(const T& NewItem)
	{
		TNode<T>* pNewNode = new TNode<T>(NewItem);
		assert(pNewNode);

		pNewNode->pNext = nullptr;
		if (m_pHead == nullptr) {
			m_pRoot = pNewNode;
			m_pHead = pNewNode;
		}
		else {
			m_pHead->pNext = pNewNode;
			m_pHead = pNewNode;
		}

		return true;
	}

	template<class T>
	bool TQueue<T>::DeQ_SL_DynMem(T& ReturnItem)
	{
		if (!m_pRoot) {
			return false;
		}

		TNode<T>* pTempNode = nullptr;
		ReturnItem = m_pRoot->Data;
		pTempNode = m_pRoot;
		m_pRoot = m_pRoot->pNext;
		if (m_pRoot == nullptr) {
			m_pHead = nullptr;
		}
		delete pTempNode;
		return true;
	}

	template<class T>
	bool TQueue<T>::Clr_SL_DynMem()
	{
		TNode<T>* pNode = m_pRoot;
		TNode<T>* pNextNode = nullptr;
		while (pNode != nullptr) {
			pNextNode = pNode->pNext;
			delete pNode;
			pNode = pNextNode;
		}
		m_pRoot = nullptr;
		m_pHead = nullptr;
		return true;
	}

	template<class T>
	bool TQueue<T>::DeQ_SL_DynMem2(T& ReturnItem)
	{
		TNode<T>* pNode = m_pRoot;
		TNode<T>* pLastNode = nullptr;
		while(pNode != nullptr){
			if (pNode->pNext == nullptr) {
				ReturnItem = pNode->Data;
				if (pLastNode != nullptr) {
					pLastNode->pNext = nullptr;
				}
				if (m_pRoot == pNode) {
					m_pRoot = nullptr;
				}
				delete pNode;
				return true;
			}
			pLastNode = pNode;
			pNode = pNode->pNext;
		}
		// empty Q
		return false;
	}

	template<class T>
	bool TQueue<T>::EnQueue(const T& NewItem)
	{
		bool bResult = false;

		switch (m_eAllocType) {
		case eAT_DynamicMem: 
			{
				switch (m_eQueueType) {
				case eQT_DoubleLinked: bResult = EnQ_DL_DynMem(NewItem);
				case eQT_SingleLinked: bResult = EnQ_SL_DynMem(NewItem);
				}
			}
			break;
		case eAT_FixedMem:
			break;
		default:
			assert(0 && "No allocation type specified");
		}

		return true;
	}


	template<class T>
	bool TQueue<T>::DeQueue(T& ReturnItem)
	{
		bool bResult = false;

		switch (m_eAllocType) {
		case eAT_DynamicMem:
		{
			switch (m_eQueueType) {
			case eQT_DoubleLinked: bResult = DeQ_DL_DynMem(ReturnItem);
			case eQT_SingleLinked: bResult = DeQ_SL_DynMem(ReturnItem);
			}
		}
		break;
		case eAT_FixedMem:
			break;
		default:
			assert(0 && "No Allocation type specified");
		}

		return bResult;
	}

	template<class T>
	bool TQueue<T>::Clear()
	{
		switch (m_eAllocType) {
		case eAT_DynamicMem:		return Clr_SL_DynMem();
		case eAT_FixedMem:			return true;
		default:
			assert(0 && "Unknown memory allocation type");
		}

		return false;
	}

	template<class T>
	bool TQueue<T>::Search(const T& _SearchItem)
	{
		TNode<T>* pNode = m_pRoot;

		while (pNode) {
			if (pNode->Data == _SearchItem) {
				return true;
			}

			pNode = pNode->pNext;
		}
		return false;
	}

}	// end namespace