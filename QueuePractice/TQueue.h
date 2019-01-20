#pragma once

namespace QueueTemplate{

	template<class T>
	class TQueue
	{
	public:
		typedef enum _QueueTypes
		{
			eQT_Illegal,

			eQT_SingleLinked,
			eQT_DoubleLinked,
			eQT_Circular,
			
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
			T			Data;
			TNode<T>*	pNext;

			TNode(const T& data) noexcept :
				Data(data), pNext(nullptr)
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
	public:
		TQueue() noexcept :
			m_pRoot(nullptr), 
			m_pHead(nullptr), 
			m_iAllocationSize(-1), 
			m_eAllocType(eAT_DynamicMem), 
			m_eQueueType(eQT_SingleLinked)
		{

		}
		TQueue(QueueType _QT, AllocationType _eAllocType, int _iAllocSize) :
			m_pRoot(nullptr),
			m_pHead(nullptr),
			m_iAllocationSize(-1),
			m_eAllocType(eAT_DynamicMem),
			m_eQueueType(eQT_SingleLinked)
		{

		}

		~TQueue(){}

		inline virtual bool EnQueue(const T& NewItem);
		inline virtual bool DeQueue(T& ReturnItem);

		inline virtual bool Clear();
	};

	template<class T>
	bool TQueue<T>::EnQueue(const T& NewItem)
	{
		return true;
	}

	template<class T>
	bool TQueue<T>::DeQueue(T& ReturnItem)
	{
		return true;
	}

	template<class T>
	bool TQueue<T>::Clear()
	{
		return true;
	}

}	// end namespace