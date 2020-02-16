#pragma once
#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"


template <class T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};



template <class T>
class LinkedList
{
public:

	LinkedList();
	~LinkedList();
	void MakeEmpty();//리스트를 비우는 함수
	int GetLength() const;//리스트 길이 받는 함수
	bool IsEmpty();//리스트가 비어있는지 확인하는 함수
	void ResetList();//레코드 포인터(current pointer) 초기화
	int GetNextItem(T& item);//current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴, 끝이면 -1을 리턴
	int Add(T item);//새로운 데이터 추가
	int Retrieve_SeqS(T& data);//입력된 정보로 데이터에서 순차적으로 검색 후 해당 데이터 출력
	int Delete(T item);//입력된 정보의 데이터 삭제
	int Replace(T item); //리스트에서 inData의 ID와 일치하는 항목을 찾아서 inData의 자료로 치환.치환하면 1을 그렇지 않으면 0을 리턴.
	int RetrieveByGenre(T& data);//장르를 기준으로 데이터에서 순차적으로 검색 후 해당 데이터 출력
	int Get(T& item);
	void SetCopied(bool copied);

private:
	T* m_Array;  //리스트 배열
	int m_Length;	//리스트 길이
	NodeType<T>* m_CurPointer;	//Node pointer for pointing current node to use iteration.
	NodeType<T>* NodeFP;//Pointer for pointing a first node.
	bool copied;
};

/**
	*	default constructor.
	*/
template <class T>
LinkedList<T>::LinkedList()
{
	m_Length = 0;
	m_CurPointer = NULL;
	NodeFP = NULL;
	copied = false;
}
/**
	*	destructor.
	*/
template <class T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	if (!copied)
		MakeEmpty();
}

/**
*	@brief	Make list empty.
*	@pre	 none.
*	@post	clear list.
*/
template <class T>
void LinkedList<T>::MakeEmpty()//리스트를 비우는 함수
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (NodeFP != NULL)
	{
		tempPtr = NodeFP;
		NodeFP = NodeFP->next;
		delete tempPtr;
	}

	m_Length = 0;
}
/**
*	@brief	Get a number of records in current list.
*	@pre	 none.
*	@post	none.
*	@return	number of records in current list.
*/
template <class T>
int LinkedList<T>::GetLength() const//리스트 길이 받는 함수
{
	return m_Length;
}

/**
*	@brief	Check capacity of list is empty.
*	@pre	 none.
*	@post	none.
*	@return	return true if list capacity is empty, otherwise return false.
*/
template <class T>
bool LinkedList<T>::IsEmpty()//리스트가 비어있는지 확인하는 함수
{
	if (m_Length == 0)
		return 1;
	else
		return 0;
}/**
	*	@brief	Initialize list iterator.
	*	@pre	 list should be initialized.
	*	@post	iterator is reset.
	*/
template <class T>
void LinkedList<T>::ResetList()//레코드 포인터(current pointer) 초기화
{
	m_CurPointer = NULL;
}
/**
*	@brief	move list iterator to the next item in list and get that item.
*	@pre	 list and list iterator should not be initialized.
*	@post	iterator is moved to next item.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, oterwise return -1.
*/
template <class T>
int LinkedList<T>::GetNextItem(T& item)//current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴, 끝이면 -1을 리턴
{
	if (IsEmpty())
	{
		//cout << "<=============리스트가 비어있습니다=============>" << endl;
		return -1;
	}
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_CurPointer == NULL)
	{
		m_CurPointer = NodeFP;
	}
	else if (m_CurPointer->next == NULL)
		return -1;
	else
		//current position 을 다음 노드로 이동
		m_CurPointer = m_CurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_CurPointer->data;
	return 1;

}
/**
*	@brief	add a new data into list
*	@pre	 list should be initialized.
*	@post	added the new record into the list.
*	@param	data	new data.
*	@return	return 1 if this function works well, otherwise 0.
*/
template <class T>
int LinkedList<T>::Add(T item)//새로운 데이터 추가
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_Length)
	{
		NodeFP = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_CurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (m_CurPointer->data > node->data)
			{
				if (pre == NULL)
				{
					node->next = m_CurPointer;
					NodeFP = node;
					break;
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				node->next = m_CurPointer;
				pre->next = node;
				break;
			}	//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_CurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_CurPointer->next = node;
				break;
			}
		}
	}

	m_Length++;

	return 1;
}

/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	 인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
template <class T>
int LinkedList<T>::Retrieve_SeqS(T& data)//입력된 정보로 데이터에서 순차적으로 검색 후 해당 데이터 출력
{
	NodeType<T>* current = NodeFP;
	while (current != NULL) {
		if (current->data == data)
		{
			data = current->data;
			return 1;
		}
		current = current->next;
	}

	return 0;
}
/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	 인수 data에 있는 genre가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 genre가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
template <class T>
int LinkedList<T>::RetrieveByGenre(T& data)//장르를 기준으로 데이터에서 순차적으로 검색 후 해당 데이터 출력
{
	NodeType<T>* current = NodeFP;
	while (current != NULL) {
		if (current->data.CompareByGenre(data) == EQUAL) {
			data = current->data;
			return 1;
		}
		current = current->next;
	}

	return 0;
}

/**
*	@brief	Initialize current pointer for an iteration through the list.
*	@pre	None.
*	@post	current pointer is prior to list. current pointer has been initialized.
*/
template<class T>
inline int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = NodeFP;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}

/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거하고 리스트 크기 동적할당으로 재조정.
	*	@pre	 인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
template <class T>
int LinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//변수 선언

	m_CurPointer = NodeFP;
	found = false;
	moreToSearch = (m_CurPointer != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == m_CurPointer->data)	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if (pre == NULL)
				NodeFP = m_CurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pre->next = m_CurPointer->next;
				delete m_CurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_Length--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre = m_CurPointer;
			m_CurPointer = m_CurPointer->next;
			moreToSearch = (m_CurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.	
}
/**
	*	@brief	리스트에서 inData의 ID와 일치하는 항목을 찾아서 inData의 자료로 치환.
	*	@pre	 인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 입력된 새로운 값으로 저장된다.
	*	@param	data	검색하고자하는 Id를 가진 inData값.
	*	@return	검색 성공시 1, 실패시 0을 리턴한다.
	*/
template <class T>
int LinkedList<T>::Replace(T item)//리스트에서 inData의 ID와 일치하는 항목을 찾아서 inData의 자료로 치환.치환하면 1을 그렇지 않으면 0을 리턴.
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = NodeFP;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}
/**
	*	@brief	node pointer값 -> copied 변수.
	*	@post    node poiner의 값이 copied에 넣어진다.
	*	@param	node pointer값이 소멸자에서 사라지는걸 방지하고자 만든 copied 변수.
	*/
template<class T>
void LinkedList<T>::SetCopied(bool copied)
{
	this->copied = copied;
}