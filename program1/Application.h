#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13


#include "ItemType.h"
#include "LinkedList.h"
#include "SingerType.h"
#include "DoublyLinkedList.h"
#include "User.h"
#define FILENAMESIZE 1024

using namespace std;


class Application
{
public:
	int movebycursor()
	{
		char ch = _getch();
		if (ch == 224)
			ch = _getch();

		switch (ch) {
		case UP:
			if (selected == 1)
				selected = menus;
			else
				selected--;
			break;
		case DOWN:
			selected = (selected % menus) + 1;
			break;
		case ENTER:
			return 1;
		}

		return 0;


	
	}
	Application();
	~Application();
	void Run();//���α׷� ����
	void RunUser();
	int GetCommand();//��� �޴� �Լ�
	int AddItem();//���� ������ �Է¹޾� ����Ʈ�� �߰�
	int ReplaceMusic(ItemType item);//����Ʈ�� �ִ� ���� ������ ���� �Է��� ������ ����
	void DisplayAllItem();//����Ʈ�� �ִ� ������ ���
	int OpenInFile(char* fileName);//���� ���¿� �Լ�
	int OpenOutFile(char* fileName);//���Ͽ� �ִ� ���ڵ带 ����Ʈ�� �����ϱ�
	int ReadDataFromFile();//���Ͽ� �ִ� ����Ʈ ������ �ҷ�����
	int WriteDataToFile();// ���Ͽ� ����Ʈ ������ �����ϱ�
	int SearchById_SequenS();//���������� �˻��ؼ� �ش� ������ ���
	int DeleteItem();//primary key �Է¹޾� �ش� �����͸� ����Ʈ���� ����
	int SearchBysName();//Ű���忡�� ���̸��� �а� list���� �� �̸��� ���� ��� ���ڵ带 ã�Ƽ� ȭ�鿡 ���
	int SearchBySinger();//������ �̸��� Ű����κ��� �Է¹޾Ƽ� �ش� ������ ��� ���� ȭ�鿡 ���
	int SearchByGenre();//�帣�� �̸��� Ű����κ��� �Է¹޾Ƽ� �ش� �帣�� ��� ���� ȭ�鿡 ���
	int SearchandReplace();//������ ���� ID�� �޾Ƽ� �˻��� �Ŀ� �����ϸ� ���� ������ Ű����κ��� �Է¹��� �� ������ ġȯ 
	int AddSongToPL();// Ű����κ��� ���� ID�� �о List���� �˻��ϰ� �����ϸ� Play List�� �߰�.���� PlayList�� Full�̸� ���� ������ ���� �����ϰ� �� ���� �߰�(Queue ����� �̿�)
	int PlayIOAddTime();//play list�� ����� ���� ���Ե� ������� ȭ�鿡 ����Ѵ�.��� �� Ű����κ��� ��� ���θ� ��� ���� ������ ������ ������ ���� �ݺ� ���.GetNextItem()�� �̿��Ͽ� play list�� �ִ� ID�� ���ʴ�� �о master list���� ã�Ƽ� ȭ�鿡 ���
	int PlayIOFreq();//play list�� ���� �÷��� �� ������� ����Ѵ�. ��� �� Ű����κ��� ��� ���θ� ��� ���� ������ ������ ������ ���� �ݺ� ���
	int DeleteSongFrPL();//Ű����κ��� ID�� �о play list���� �ش� ���ڵ带 �����Ѵ�
	int AddSinger();//���ο� ������ �߰�
	int AddSong(ItemType item); //�߰��� ���� ������ �˻��ϰ� ������ �����ϸ� �ش� ������ songlist�� ���� �߰��Ѵ�.�������� ������ ������ �߰��ϰ� �Էµ� ���� �߰��Ѵ�.
	int SearchBySingerPL();//singerList���� ������ �˻��ϰ� �ش� ������ �θ� ��� ���� �ڼ��� ������ ȭ�鿡 ����Ѵ�
	int registeruser();//ȸ������
	int login();//�α��� ���� �Լ�
	int getlogincommand();//�α���,ȸ������ �� �ϳ��� �����Ͽ� Ŀ�ǵ� �Է�

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	LinkedList<ItemType> m_List;
	DoublyLinkedList<SingerType> m_SList;//singer list
	DoublyLinkedList<User> m_UserList;
	int m_Command;
	int plCount;//�÷��� �� Ƚ��
	User currentuser;
	int selected;
	int menus;

	void printMenuItem(int no, const char* name);
};

