#pragma once
#include <iostream>
#include <string>
#include "PlayItem.h"
#include "DoublyLinkedList.h"
using namespace std;

class User
{
public:
	void setid(string inid);
	void setpassword(string inpassword);
	string getid();
	string getpassword();
	int checklogin(string nId, string nPassword);//�α��Ή���� Ȯ���ϴ� �Լ�
	void setRecordFromKB();//����ڷκ��� �α��ΰ��õ����� �Է¹���
	void SetIdFromKB();//����ڷκ��� id �Է¹���
	void SetPasswordFromKB();//����ڷκ��� password �Է¹���
	void SetIsAdminFromKB();//����ڷκ��� isAdmin �Է¹���
	bool isAdmin();//admin ����
	bool operator>(User item);//������ �����ε�
	bool operator==(User item);//������ �����ε�
	DoublyLinkedList<PlayItem> m_pList;
private:
	string id;
	string password;
	bool admin;

};