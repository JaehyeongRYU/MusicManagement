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
		m_iFront = 0;//dequeue시 +1
		m_iRear = 0;//enqueue시 +1
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
		m_iFront = 0;//dequeue시 +1
		m_iRear = 0;//enqueue시 +1
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
			return true;//큐가 가득찼으면 true 리턴
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
*	@brief	queue에 회전하면서 값을 채움.
*	@pre	queue가 초기화 되어야함
*	@post	가득차있으면 FullStack Exception을 throw함, 아니면 새로운 값을 추가함,rear값 증가
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
*	@brief	queue에 회전하면서 값을 삭제(=front값이 하나 증가)
*	@pre	Stack has been initialized.
*	@post	비어있으면 empty Exception을 throw;아니면 맨위의 값을 삭제
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
	void ResetList()// pointer가 front 가리키도록 세팅 
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
	bool GetNextItem(T& item)//empty가 아니면 pointer를 증가시키고 pointe가 가리키는 item과 true를 리턴 
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
	*	@brief	item pointer을 찾으면 item에 해당 아이템 포인터의 데이터를 넣어준다.
	*	@pre	 인수 data에 있는 item pointer가 PlayList 내에 존재하는 값이어야 한다.
	*	@post	PlayList 내에서 찾은 item pointer의 데이터를 item에 입력된다.
	*	@param	data	찾고자 하는 item pointer가 입력된 T&값. 발견한 item pointer data 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Search(T& item)//item의 ID와 일치하는 레코드를 Queue에서 리턴 
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
		*	@brief	id가 일치하는 item을 찾아서 해당 item을 Queue에서 삭제
		*	@pre	 인수 data에 있는 id가 PlayList 내에 존재하는 값이어야 한다.
		*	@post	PlayList 내에 해당 item이 제거된다.
		*	@param	data	제거하고자 하는 id가 입력된 T값.
		*	@return	성공시 1, 실패시 0을 리턴한다.
		*/
	int Delete(T item)//item의 ID와 일치하는 레코드를 Queue에서삭제 
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
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 Queue에서 검색
	*	@pre	 인수 data에 있는 id가 PlayList 내에 존재하는 값이어야 한다.
	*	@post	PlayList 내에 해당 item이 검색된다.
	*	@param	data	검색하고자 하는 id가 입력된 T값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T item)//item의 ID와 일치하는 레코드를 Queue에서 찾아서 item에 들어있는 정보로 대체
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
	int m_Count;//enqueue 실행된 횟수
	int m_Size;//현재 list 안에 들어있는 item의 수

	T* m_pItems; // item pointer
};