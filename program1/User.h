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
	int checklogin(string nId, string nPassword);//로그인됬는지 확인하는 함수
	void setRecordFromKB();//사용자로부터 로그인관련데이터 입력받음
	void SetIdFromKB();//사용자로부터 id 입력받음
	void SetPasswordFromKB();//사용자로부터 password 입력받음
	void SetIsAdminFromKB();//사용자로부터 isAdmin 입력받음
	bool isAdmin();//admin 리턴
	bool operator>(User item);//연산자 오버로딩
	bool operator==(User item);//연산자 오버로딩
	DoublyLinkedList<PlayItem> m_pList;
private:
	string id;
	string password;
	bool admin;

};