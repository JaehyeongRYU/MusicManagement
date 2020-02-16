
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum RelationType { LESS, GREATER, EQUAL };


#pragma once
class ItemType
{
public:

	ItemType();
	~ItemType();
	int getsType();
	string getsName();
	string getsWriter();
	string getsinger();
	int getgenre();
	string getsNumber();

	void setsType(int insType);
	void setsName(string insName);
	void setsWriter(string insWriter);
	void setsinger(string insinger);
	void setgenre(int ingenre);
	void setsNumber(string insNumber);
	void setRecord(int insType, string insName, string insWriter, string insinger, int ingenre, string insNumber);
	void DisplaysTypeOnScreen();//화면에 sType 출력
	void DisplaysNameOnScreen();//화면에 sName 출력
	void DisplaysWriterOnScreen();//화면에 sWriter 출력
	void DisplaysingerOnScreen();//화면에 singer 출력
	void DisplaygenreOnScreen();//화면에 genre 출력
	void DisplaysNumberOnScreen();//화면에 sNumber 출력
	void DisplayRecordOnScreen();//화면에 모든 Record 출력
	void SetsTypeFromKB();//사용자로부터 sType 입력 함수
	void SetsNameFromKB();//사용자로부터 sName 입력 함수
	void SetsWriterFromKB();//사용자로부터 sWriter 입력 함수
	void SetsingerFromKB();//사용자로부터 singer 입력 함수
	void SetgenreFromKB();//사용자로부터 genre 입력 함수
	void SetsNumberFromKB();//사용자로부터 sNumber 입력 함수
	void SetRecordFromKB();//사용자 입력 함수 6개 호출
	int ReadDataFromFile(ifstream& fin);//파일에서 데이터 읽는 함수
	int WriteDataToFile(ofstream& fout);//파일에서 데이터 입력 함수
	RelationType Compare(const ItemType& data); //primary key(ID)를 기준으로 학생 정보를 비교하는 함수
	RelationType CompareByGenre(const ItemType& data); //장르를 기준으로 학생 정보를 비교하는 함수
	bool operator>(ItemType item);//연산자 오버로딩
	bool operator==(ItemType item);//연산자 오버로딩
protected:
	int sType;//곡 타입 1:가요, 2:연주곡
	string sName;//곡명
	string sWriter;//작곡가
	string singer;//가수
	int genre;//장르
	string sNumber;//곡 고유번호

};

