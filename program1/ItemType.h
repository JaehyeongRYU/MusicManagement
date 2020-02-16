
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
	void DisplaysTypeOnScreen();//ȭ�鿡 sType ���
	void DisplaysNameOnScreen();//ȭ�鿡 sName ���
	void DisplaysWriterOnScreen();//ȭ�鿡 sWriter ���
	void DisplaysingerOnScreen();//ȭ�鿡 singer ���
	void DisplaygenreOnScreen();//ȭ�鿡 genre ���
	void DisplaysNumberOnScreen();//ȭ�鿡 sNumber ���
	void DisplayRecordOnScreen();//ȭ�鿡 ��� Record ���
	void SetsTypeFromKB();//����ڷκ��� sType �Է� �Լ�
	void SetsNameFromKB();//����ڷκ��� sName �Է� �Լ�
	void SetsWriterFromKB();//����ڷκ��� sWriter �Է� �Լ�
	void SetsingerFromKB();//����ڷκ��� singer �Է� �Լ�
	void SetgenreFromKB();//����ڷκ��� genre �Է� �Լ�
	void SetsNumberFromKB();//����ڷκ��� sNumber �Է� �Լ�
	void SetRecordFromKB();//����� �Է� �Լ� 6�� ȣ��
	int ReadDataFromFile(ifstream& fin);//���Ͽ��� ������ �д� �Լ�
	int WriteDataToFile(ofstream& fout);//���Ͽ��� ������ �Է� �Լ�
	RelationType Compare(const ItemType& data); //primary key(ID)�� �������� �л� ������ ���ϴ� �Լ�
	RelationType CompareByGenre(const ItemType& data); //�帣�� �������� �л� ������ ���ϴ� �Լ�
	bool operator>(ItemType item);//������ �����ε�
	bool operator==(ItemType item);//������ �����ε�
protected:
	int sType;//�� Ÿ�� 1:����, 2:���ְ�
	string sName;//���
	string sWriter;//�۰
	string singer;//����
	int genre;//�帣
	string sNumber;//�� ������ȣ

};

