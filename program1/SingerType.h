#pragma once
#include <iostream>
#include <string>

#include "LinkedList.h"


using namespace std;

struct SongType //Song Type 구조체
{
	string Sid;
	string Sname;
	void setSongIdFromKB();//사용자로부터 노래 아이디 입력받음
	void setSongnameFromKB();// 사용자로부터 노래 이름 입력받음
};

bool operator==(const SongType& a, const SongType& b);//연산자 오버로딩
bool operator>(const SongType& a, const SongType& b);//연산자 오버로딩

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
	void setSingerNameFromKB();//사용자로부터 가수 이름 입력받음
	void setSingerAgeFromKB();//사용자로부터 가수 나이 입력받음
	void setSingerGenderFromKB();//사용자로부터 가수 성별 입력받음
	void setRecordFromKB();//사용자로부터 가수 기록 입력받음
	void addSong(SongType& song);//song list에 song 추가
	void ResetList();//레코드 포인터(current pointer) 초기화
	int GetNextItem(SongType& item);//current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴, 끝이면 -1을 리턴
	void SetCopied(bool copied);//node pointer값을 copied에 넣어준다.


	bool operator==(SingerType& singer);//연산자 오버로딩
	bool operator>(SingerType& singer);//연산자 오버로딩

private:
	string SingerName;
	int SingerAge;
	int SingerGender;//남자 : 1, 여자 : 0

	LinkedList<SongType> songList;

};

