#pragma once
#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#define maxsize 7;
#include "PlayItem.h"
template <class T>
class PlayList
{
public:

	/**
		*	default constructor.
		*/
	PlayList()// Create circular queue(default size) using dynamic allocation 
	{
		m_iFront = 0;//dequeue�� +1
		m_iRear = 0;//enqueue�� +1
		m_nMaxQueue = maxsize;//maximum size of the circular queue
		m_pItems = new T[m_nMaxQueue];//item pointer
		m_Count = 0;
		m_Size = 0;
	}

	/**
		*	max size constructor.
		*/
	PlayList(int max)// Create circular queue(max size) using dynamic allocation 
	{
		m_iFront = 0;//dequeue�� +1
		m_iRear = 0;//enqueue�� +1
		m_nMaxQueue = max;//maximum size of the circular queue
		m_pItems = new T[max];//item pointer
		m_Count = 0;
		m_Size = 0;
	}

	/**
		*	default destructor, release circular queue
		*/
	~PlayList() // default destructor, release circular queue
	{
		delete[] m_pItems;
	}
	/**
*	@brief	Check capacity of PlayList is full.
*	@pre	 none.
*	@post	none.
*	@return	return true if PlayList capacity reached to the upper bound, otherwise return false.
*/
	bool IsFull()// check the circular queue is full or not
	{
		if ((m_iRear + 1) % m_nMaxQueue == m_iFront)
		{
			cout << "-----------FULL QUEUE!-----------" << endl;
			return true;//ť�� ����á���� true ����
		}
		else
			return false;
	}
	/**
*	@brief	Check capacity of PlayList is empty.
*	@pre	 none.
*	@post	none.
*	@return	return true if PlayList capacity is empty, otherwise return false.
*/
	bool IsEmpty() // check the circular queue is empty or not 
	{
		if (m_iRear == m_iFront)
		{
			cout << "----------- EMPTY QUEUE!-----------" << endl;
			return true;
		}
		else
			return false;
	}
	/**
*	@brief	Make PlayList empty.
*	@pre	 none.
*	@post	clear PlayList.
*/
	void MakeEmpty() // make empty circular queue 
	{
		m_iRear = m_iFront;
	}
	/**
*	@brief	queue�� ȸ���ϸ鼭 ���� ä��.
*	@pre	queue�� �ʱ�ȭ �Ǿ����
*	@post	������������ FullStack Exception�� throw��, �ƴϸ� ���ο� ���� �߰���,rear�� ����
*/
	int EnQueue(T item) // if circular queue has space then add item to top 
	{
		if (IsFull())
		{
			return 0;
		}

		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item;
		m_Count++;
		m_Size++;
		return 1;
	}
	/**
*	@brief	queue�� ȸ���ϸ鼭 ���� ����(=front���� �ϳ� ����)
*	@pre	Stack has been initialized.
*	@post	��������� empty Exception�� throw;�ƴϸ� ������ ���� ����
*/
	int DeQueue(T& item) // if circular queue has any item then return item and delete it. 
	{
		if (IsEmpty())
		{
			return 0;
		}

		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront];
		m_Size--;
	}
	/**
*	@brief	Print all the items in the stack on screen
*	@pre	Stack has been initialized.
*	@post	None.
*/
	void Print()// display all item on screen
	{
		int i = m_iFront;
		while (1)
		{
			i = (i + 1) % m_nMaxQueue;


			cout << m_pItems[i] << endl;

			if (i == m_iRear)
				return 0;
		}
	}
	/**
	*	@brief	Initialize PlayList iterator.
	*	@pre	 PlayList should be initialized.
	*	@post	iterator is front.
	*/
	void ResetList()// pointer�� front ����Ű���� ���� 
	{
		m_CurPointer = m_iFront;
	}
	/**
*	@brief	move Playlist iterator to the next item by (iterator+1)%m_nMaxQueue in list and get that item.
*	@pre	 list and list iterator should not be initialized.
*	@post	iterator is moved to next item by (iterator+1)%m_nMaxQueue.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	if IsEmpty()=0  -> return 1, oterwise return 0.
*/
	bool GetNextItem(T& item)//empty�� �ƴϸ� pointer�� ������Ű�� pointe�� ����Ű�� item�� true�� ���� 
	{
		if (!IsEmpty())
		{
			m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
			item = m_pItems[m_CurPointer];
			return 1;
		}
		else
			return 0;
	}
	/**
	*	@brief	item pointer�� ã���� item�� �ش� ������ �������� �����͸� �־��ش�.
	*	@pre	 �μ� data�� �ִ� item pointer�� PlayList ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	PlayList ������ ã�� item pointer�� �����͸� item�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� item pointer�� �Էµ� T&��. �߰��� item pointer data ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Search(T& item)//item�� ID�� ��ġ�ϴ� ���ڵ带 Queue���� ���� 
	{
		int i = m_iFront;
		while (1)
		{
			i = (i + 1) % m_nMaxQueue;


			if (item.Compare(m_pItems[i]) == EQUAL)
			{
				item = m_pItems[i];
				return 1;
			}

			if (i == m_iRear)
				return 0;
		}
	}

	/**
		*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� Queue���� ����
		*	@pre	 �μ� data�� �ִ� id�� PlayList ���� �����ϴ� ���̾�� �Ѵ�.
		*	@post	PlayList ���� �ش� item�� ���ŵȴ�.
		*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� T��.
		*	@return	������ 1, ���н� 0�� �����Ѵ�.
		*/
	int Delete(T item)//item�� ID�� ��ġ�ϴ� ���ڵ带 Queue�������� 
	{
		int i = m_iFront;
		while (1)
		{
			i = (i + 1) % m_nMaxQueue;

			if (m_pItems[i].Compare(item) == EQUAL)
			{
				while (i != m_iRear)
				{
					m_pItems[i] = m_pItems[(i + 1) % m_nMaxQueue];
					i = (i + 1) % m_nMaxQueue;
				}

				m_iRear = (m_iRear + m_nMaxQueue - 1) % m_nMaxQueue;
				m_Size--;
				return 1;
			}

			if (i == m_iRear)
				return 0;
		}
	}
	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� Queue���� �˻�
	*	@pre	 �μ� data�� �ִ� id�� PlayList ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	PlayList ���� �ش� item�� �˻��ȴ�.
	*	@param	data	�˻��ϰ��� �ϴ� id�� �Էµ� T��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T item)//item�� ID�� ��ġ�ϴ� ���ڵ带 Queue���� ã�Ƽ� item�� ����ִ� ������ ��ü
	{
		int i = m_iFront;
		while (1)
		{
			i = (i + 1) % m_nMaxQueue;

			if (m_pItems[i].Compare(item) == EQUAL)
			{
				m_pItems[i] = item;
				return 1;
			}

			if (i == m_iRear)
				return 0;
		}
	}
	/**
	*	@brief	Get enqueue count
	*	@pre	enqueue count is set.
	*	@post	none.
	*	@return	enqueue count.
	*/
	int GetCount()
	{
		return m_Count;
	}
	/**
*	@brief	Get item number
*	@pre	item number is set.
*	@post	none.
*	@return	item number.
*/
	int GetSize()
	{
		return m_Size;
	}

private:
	int m_iFront; // front index of the circular queue 
	int m_iRear; // rear index of the circular queue 
	int m_nMaxQueue; // maximum size of the circular queue 
	int m_CurPointer;	//current pointer
	int m_Count;//enqueue ����� Ƚ��
	int m_Size;//���� list �ȿ� ����ִ� item�� ��

	T* m_pItems; // item pointer
};