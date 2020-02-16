#pragma once
#include <iostream>
#include <fstream>	
#include <string>

using namespace std;

#include "ItemType.h"


template <class T>
struct DoublyNodeType
{
	T data;	///< A data for each node.
	DoublyNodeType* prev; //< A node pointer to point precede node.
	DoublyNodeType* next;//< A node pointer to point succeed node.
};


template <class T>
class DoublyLinkedList
{
public:

	DoublyLinkedList();
	~DoublyLinkedList();
	void MakeEmpty();//����Ʈ�� ���� �Լ�
	int GetLength() const;//����Ʈ ���� �޴� �Լ�
	bool IsEmpty();//����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�
	void ResetList();//���ڵ� ������(current pointer) �ʱ�ȭ
	int GetNextItem(T& item);//current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ����, ���̸� -1�� ����
	int GetPrevItem(T& item);//current pointer�� �ϳ� ���ҽ�Ű�� ���� �ƴϸ� record index�� ����, ���̸� -1�� ����
	int Add(T item);//���ο� ������ �߰�
	int Retrieve_SeqS(T& data);//�Էµ� ������ �����Ϳ��� ���������� �˻� �� �ش� ������ ���
	int Delete(T item);//�Էµ� ������ ������ ����
	int Replace(T item); //����Ʈ���� inData�� ID�� ��ġ�ϴ� �׸��� ã�Ƽ� inData�� �ڷ�� ġȯ.ġȯ�ϸ� 1�� �׷��� ������ 0�� ����.
	int RetrieveByGenre(T& data);//�帣�� �������� �����Ϳ��� ���������� �˻� �� �ش� ������ ���
	int Get(T& item);
	void SetCopied(bool copied);

private:
	T* m_Array;  //����Ʈ �迭
	int m_Length;	//����Ʈ ����
	DoublyNodeType<T>* m_CurPointer;	//Node pointer for pointing current node to use iteration.
	DoublyNodeType<T>* NodeFP;//Pointer for pointing a first node.
	DoublyNodeType<T>* NodeLP;//Pointer for pointing a last node.
	bool copied;
};

/**
	*	default constructor.
	*/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
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
DoublyLinkedList<T>::~DoublyLinkedList()
{
	//����Ʈ���� ��� node ����
	if (!copied)
		MakeEmpty();
}

/**
*	@brief	Make list empty.
*	@pre	 none.
*	@post	clear list.
*/
template <class T>
void DoublyLinkedList<T>::MakeEmpty()//����Ʈ�� ���� �Լ�
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	DoublyNodeType<T>* tempPtr;

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
int DoublyLinkedList<T>::GetLength() const//����Ʈ ���� �޴� �Լ�
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
bool DoublyLinkedList<T>::IsEmpty()//����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�
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
void DoublyLinkedList<T>::ResetList()//���ڵ� ������(current pointer) �ʱ�ȭ
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
int DoublyLinkedList<T>::GetNextItem(T& item)//current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ����, ���̸� -1�� ����
{
	if (IsEmpty())
	{
		//cout << "<=============����Ʈ�� ����ֽ��ϴ�=============>" << endl;
		return -1;
	}
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_CurPointer == NULL)
	{
		m_CurPointer = NodeFP;
	}
	else if (m_CurPointer->next == NULL)
		return -1;
	else
		//current position �� ���� ���� �̵�
		m_CurPointer = m_CurPointer->next;

	//item �� current position �� info �� ����
	item = m_CurPointer->data;
	return 1;

}

/**
*	@brief	move list iterator to the previous item in list and get that item.
*	@pre	 list and list iterator should not be initialized.
*	@post	iterator is moved to previous item.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, oterwise return -1.
*/
template <class T>
int DoublyLinkedList<T>::GetPrevItem(T& item)//current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ����, ���̸� -1�� ����
{
	if (IsEmpty())
	{
		//cout << "<=============����Ʈ�� ����ֽ��ϴ�=============>" << endl;
		return -1;
	}
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_CurPointer == NULL)
	{
		m_CurPointer = NodeLP;
	}
	else if (m_CurPointer->prev == NULL)
		return -1;
	else
		//current position �� ���� ���� �̵�
		m_CurPointer = m_CurPointer->prev;

	//item �� current position �� info �� ����
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
int DoublyLinkedList<T>::Add(T item)//���ο� ������ �߰�
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyNodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;
	node->prev = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_Length)
	{
		NodeFP = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_CurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (m_CurPointer->data > node->data)
			{
				if (pre == NULL)
				{
					node->next = m_CurPointer;
					NodeFP = node;
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
				m_CurPointer->prev = node;
				node->next = m_CurPointer;
				node->prev = pre;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_CurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_CurPointer->next = node;
				node->prev = m_CurPointer;
				break;
			}
		}
	}

	NodeLP = node;
	m_Length++;

	return 1;
}

/**
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	 �μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
template <class T>
int DoublyLinkedList<T>::Retrieve_SeqS(T& data)//�Էµ� ������ �����Ϳ��� ���������� �˻� �� �ش� ������ ���
{
	DoublyNodeType<T>* current = NodeFP;
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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	 �μ� data�� �ִ� genre�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� genre�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
template <class T>
int DoublyLinkedList<T>::RetrieveByGenre(T& data)//�帣�� �������� �����Ϳ��� ���������� �˻� �� �ش� ������ ���
{
	DoublyNodeType<T>* current = NodeFP;
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
inline int DoublyLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	DoublyNodeType<T>* location;	//���� ����

	location = NodeFP;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����ϰ� ����Ʈ ũ�� �����Ҵ����� ������.
	*	@pre	 �μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
template <class T>
int DoublyLinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	DoublyNodeType<T>* pre = NULL;	//���� ����

	m_CurPointer = NodeFP;
	found = false;
	moreToSearch = (m_CurPointer != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == m_CurPointer->data)	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����


			if (m_CurPointer->next != NULL)
				m_CurPointer->next->prev = pre;

			if (pre == NULL)
				NodeFP = m_CurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pre->next = m_CurPointer->next;
				delete m_CurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.

			if (m_CurPointer == NodeLP) {
				NodeLP = m_CurPointer->prev;
			}

			m_Length--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre = m_CurPointer;
			m_CurPointer = m_CurPointer->next;
			moreToSearch = (m_CurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.	
}
/**
	*	@brief	����Ʈ���� inData�� ID�� ��ġ�ϴ� �׸��� ã�Ƽ� inData�� �ڷ�� ġȯ.
	*	@pre	 �μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� �Էµ� ���ο� ������ ����ȴ�.
	*	@param	data	�˻��ϰ����ϴ� Id�� ���� inData��.
	*	@return	�˻� ������ 1, ���н� 0�� �����Ѵ�.
	*/
template <class T>
int DoublyLinkedList<T>::Replace(T item)//����Ʈ���� inData�� ID�� ��ġ�ϴ� �׸��� ã�Ƽ� inData�� �ڷ�� ġȯ.ġȯ�ϸ� 1�� �׷��� ������ 0�� ����.
{
	bool moreToSearch, found;
	DoublyNodeType<T>* location;	//���� ����

	location = NodeFP;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}
/**
	*	@brief	node pointer�� -> copied ����.
	*	@post    node poiner�� ���� copied�� �־�����.
	*	@param	node pointer���� �Ҹ��ڿ��� ������°� �����ϰ��� ���� copied ����.
	*/
template<class T>
void DoublyLinkedList<T>::SetCopied(bool copied)
{
	this->copied = copied;
}