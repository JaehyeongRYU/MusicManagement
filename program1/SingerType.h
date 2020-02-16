#pragma once
#include <iostream>
#include <string>

#include "LinkedList.h"


using namespace std;

struct SongType //Song Type ����ü
{
	string Sid;
	string Sname;
	void setSongIdFromKB();//����ڷκ��� �뷡 ���̵� �Է¹���
	void setSongnameFromKB();// ����ڷκ��� �뷡 �̸� �Է¹���
};

bool operator==(const SongType& a, const SongType& b);//������ �����ε�
bool operator>(const SongType& a, const SongType& b);//������ �����ε�

class SingerType
{
public:
	string getSingerName();
	int getSingerAge();
	int getSingerGender();
	void setSingerName(string inSName);
	void setSingerAge(int inSAge);
	void setSingerGender(int inSGender);
	void setRecord(string inSName, int inSAge, int inSGender);
	void setSingerNameFromKB();//����ڷκ��� ���� �̸� �Է¹���
	void setSingerAgeFromKB();//����ڷκ��� ���� ���� �Է¹���
	void setSingerGenderFromKB();//����ڷκ��� ���� ���� �Է¹���
	void setRecordFromKB();//����ڷκ��� ���� ��� �Է¹���
	void addSong(SongType& song);//song list�� song �߰�
	void ResetList();//���ڵ� ������(current pointer) �ʱ�ȭ
	int GetNextItem(SongType& item);//current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ����, ���̸� -1�� ����
	void SetCopied(bool copied);//node pointer���� copied�� �־��ش�.


	bool operator==(SingerType& singer);//������ �����ε�
	bool operator>(SingerType& singer);//������ �����ε�

private:
	string SingerName;
	int SingerAge;
	int SingerGender;//���� : 1, ���� : 0

	LinkedList<SongType> songList;

};

