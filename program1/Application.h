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
	void Run();//프로그램 실행
	void RunUser();
	int GetCommand();//명령 받는 함수
	int AddItem();//음원 정보를 입력받아 리스트에 추가
	int ReplaceMusic(ItemType item);//리스트에 있는 음원 정보를 새로 입력한 정보로 수정
	void DisplayAllItem();//리스트에 있는 데이터 출력
	int OpenInFile(char* fileName);//파일 오픈용 함수
	int OpenOutFile(char* fileName);//파일에 있는 리코드를 리스트에 저장하기
	int ReadDataFromFile();//파일에 있는 리스트 데이터 불러오기
	int WriteDataToFile();// 파일에 리스트 데이터 저장하기
	int SearchById_SequenS();//순차적으로 검색해서 해당 데이터 출력
	int DeleteItem();//primary key 입력받아 해당 데이터를 리스트에서 삭제
	int SearchBysName();//키보드에서 곡이름을 읽고 list에서 이 이름을 가진 모든 레코드를 찾아서 화면에 출력
	int SearchBySinger();//가수의 이름을 키보드로부터 입력받아서 해당 가수의 모든 곡을 화면에 출력
	int SearchByGenre();//장르의 이름을 키보드로부터 입력받아서 해당 장르의 모든 곡을 화면에 출력
	int SearchandReplace();//수정할 곡의 ID를 받아서 검색한 후에 존재하면 기존 정보를 키보드로부터 입력받은 새 정보를 치환 
	int AddSongToPL();// 키보드로부터 곡의 ID를 읽어서 List에서 검색하고 존재하면 Play List에 추가.만약 PlayList가 Full이면 가장 오래된 것을 삭제하고 새 곡을 추가(Queue 기능을 이용)
	int PlayIOAddTime();//play list에 저장된 곡을 삽입된 순서대로 화면에 출력한다.출력 후 키보드로부터 계속 여부를 물어서 종료 조건이 만족될 때까지 무한 반복 출력.GetNextItem()을 이용하여 play list에 있는 ID를 차례대로 읽어서 master list에서 찾아서 화면에 출력
	int PlayIOFreq();//play list를 자주 플레이 된 순서대로 재생한다. 출력 후 키보드로부터 계속 여부를 물어서 종료 조건이 만족될 때까지 무한 반복 출력
	int DeleteSongFrPL();//키보드로부터 ID를 읽어서 play list에서 해당 레코드를 삭제한다
	int AddSinger();//새로운 가수를 추가
	int AddSong(ItemType item); //추가할 곡의 가수를 검색하고 가수가 존재하면 해당 가수의 songlist에 곡을 추가한다.존재하지 않으면 가수를 추가하고 입력된 곡을 추가한다.
	int SearchBySingerPL();//singerList에서 가수를 검색하고 해당 가수가 부른 모든 곡의 자세한 정보를 화면에 출력한다
	int registeruser();//회원가입
	int login();//로그인 동작 함수
	int getlogincommand();//로그인,회원가입 중 하나를 결정하여 커맨드 입력

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	LinkedList<ItemType> m_List;
	DoublyLinkedList<SingerType> m_SList;//singer list
	DoublyLinkedList<User> m_UserList;
	int m_Command;
	int plCount;//플레이 된 횟수
	User currentuser;
	int selected;
	int menus;

	void printMenuItem(int no, const char* name);
};

