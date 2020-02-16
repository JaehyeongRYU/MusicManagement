#include "Application.h"
#include "PlayItemFreq.h"
/**
	*	default constructor.
	*/
Application::Application()
{
	m_Command = 0;
	plCount = 0;
	menus = 2;
	selected = 1;
}
/**
	*	destructor.
	*/
Application::~Application()
{
}

void Application::Run()
{
	while (1)
	{
		int command = getlogincommand();

		if (command == 1 && login())
		{
			RunUser();
		}
		else if (command == 2)
		{
			registeruser();
		}
		//else if (command != 0 && command != 1 && command != 2)
		//	cout << "   <============1 또는 2 를 입력해주세요!!!============>" << endl;
		//else
		//	cout << "   <=======잘못된 입력입니다! 다시 입력해주세요!=======>" << endl;
	}
}

/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
void Application::RunUser()//프로그램 실행
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			AddItem();
			_getch();
			break;
		case 2:
			DeleteItem();
			_getch();
			break;
		case 3:
			SearchBySinger();
			_getch(); 
			break;
		case 4:
			SearchByGenre();
			_getch();
			break;
		case 5:
			DisplayAllItem();
			_getch();
			break;
		case 6:
			m_List.MakeEmpty();
			_getch();
			break;
		case 7:
			SearchandReplace();
			_getch();
			break;
		case 8:
			ReadDataFromFile();
			_getch();
			break;
		case 9:
			WriteDataToFile();
			_getch(); 
			break;
		case 10:
			AddSongToPL();
			_getch();
			break;
		case 11:
			PlayIOAddTime();
			_getch();
			break;
		case 12:
			DeleteSongFrPL();
			_getch();
			break;
		case 13:
			AddSinger();
			_getch();
			break;
		case 14:
			SearchBySingerPL();
			_getch();
			break;
		case 15:
			PlayIOFreq();
			_getch();
			break;
		case 16:
			return;
		}
	}
}
/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
int Application::GetCommand()//명령 받는 함수
{
	system("cls");

	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t"; 
	printMenuItem(1, "Add Music");
	cout << "\t";
	printMenuItem(2, "Delete Music");
	cout << "\t";
	printMenuItem(3, "Search Music by Singer");
	cout << "\t";
	printMenuItem(4, "Search Music by Genre");
	cout << "\t";
	printMenuItem(5, "Print all on screen");
	cout << "\t";
	printMenuItem(6, "Make Empty List");
	cout << "\t";
	printMenuItem(7, "Search & Replace");
	cout << "\t";
	printMenuItem(8, "Get From File");
	cout << "\t";
	printMenuItem(9, "Put To File");
	cout << "\t";
	printMenuItem(10, "Add To PlayList");
	cout << "\t";
	printMenuItem(11, "Play Insert Order");
	cout << "\t";
	printMenuItem(12, "Delete From PlayList");
	cout << "\t";
	printMenuItem(13, "Add Singer to Singer List ");
	cout << "\t";
	printMenuItem(14, "Search Music By Singer From Singer List");
	cout << "\t";
	printMenuItem(15, "Play Freq Order ");
	cout << "\t";
	printMenuItem(16, "Quit");

	cout << endl << "		 Choose a Command--> " << endl;

	if (movebycursor())
		return selected;

	return 0;
}
/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::AddItem()//음원 정보를 입력받아 리스트에 추가
{
	if (!currentuser.isAdmin())
	{
		cout << "   <==========관리자만 접근할 수 있습니다.==========>" << endl;

		return 0;
	}
	ItemType item;

	item.SetRecordFromKB();
	AddSong(item);
	m_List.Add(item);
	cout << "   <====================================>" << endl;
	_getch();

	return 1;
}


/**
	*	@brief	replace new record into old record in the list.
	*	@pre	list should be initialized.
	*	@post	new record is added into old record in the list.
	*	@return	return 0
	*/
int Application::ReplaceMusic(ItemType item)
{
	if (!currentuser.isAdmin())
		return 0;

	item.SetsTypeFromKB();
	item.SetsNameFromKB();
	item.SetsWriterFromKB();
	item.SetgenreFromKB();
	m_List.Replace(item);
	return 0;
}
/**
	*	@brief	순차적으로 검색해서 해당 데이터 출력
	*	@pre	 list should be initialized.
	*	@post	search the record  by Id.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchById_SequenS()//순차적으로 검색해서 해당 데이터 출력
{
	ItemType item;
	item.SetsNumberFromKB(); //id입력받는다.

	if (m_List.Retrieve_SeqS(item)) //0이 아니면(찾으면)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << "   <======== Music Not Found!==========>" << endl;
	return 0;	//실패(0)을 리턴
}


/**
	*	@brief	Id입력받아 해당 데이터를 리스트에서 삭제
	*	@pre	 list should be initialized.
	*	@post	delete the record which is found by Id.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::DeleteItem()//Id입력받아 해당 데이터를 리스트에서 삭제
{
	if (!currentuser.isAdmin())
		return 0;

	int pre = m_List.GetLength();//이전 item개수를 받아온다.
	ItemType item;
	item.SetsNumberFromKB();

	m_List.Delete(item);

	if (pre > m_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "   <========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "   <========DELETE FAIL !=======>" << endl;
	return 0;
}
/**
	*	@brief	키보드에서 이름을 읽고 list에서 이 이름을 가진 모든 레코드를 찾아서 화면에 출력
	*	@pre	 list should be initialized.
	*	@post	search the record  by Name.
	*	@return	1값을 리턴
	*/
int Application::SearchBysName()//키보드에서 이름을 읽고 list에서 이 이름을 가진 모든 레코드를 찾아서 화면에 출력
{
	ItemType item;
	item.SetsNameFromKB();

	ItemType data;
	m_List.ResetList();
	int curIndex;
	while (1)
	{
		curIndex = m_List.GetNextItem(data);

		if (curIndex == -1)
			break;

		if (data.getsName().find(item.getsName()) != string::npos)
		{
			cout << "   <====================================>" << endl;
			data.DisplayRecordOnScreen();
		}
		else
		{
			cout << "   <====================================>" << endl;
			cout << "   <======== Music Not Found!==========>" << endl;
			cout << "   <====================================>" << endl;
		}
	}

	return 1;
}
/**
	*	@brief	키보드에서 가수 이름을 읽고 list에서 이 가수 이름을 가진 모든 레코드를 찾아서 화면에 출력
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	1값을 리턴
	*/
int Application::SearchBySinger()
{
	ItemType item;
	item.SetsingerFromKB();

	ItemType data;
	m_List.ResetList();
	int curIndex;
	while (1)
	{
		curIndex = m_List.GetNextItem(data);

		if (curIndex == -1)
			break;

		if (data.getsinger().find(item.getsinger()) != string::npos)
		{
			cout << "   <====================================>" << endl;
			data.DisplayRecordOnScreen();
			return 1;

			cout << "   <====================================>" << endl;
		}
	}
	cout << "   <======== Music Not Found!==========>" << endl;
	cout << "   <====================================>" << endl;

	return 1;
}
/**
	*	@brief	키보드에서 가수 이름을 읽고 해당 가수가 부른 노래를 검색해서 출력
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	검색하는데 성공하면 1값을 리턴, 그게 아니면 0을 리턴
	*/
int Application::SearchBySingerPL()////singerList에서 가수를 검색하고 해당 가수가 부른 모든 곡의 자세한 정보를 화면에 출력한다
{
	SingerType item;
	item.setSingerNameFromKB();

	if (m_SList.Retrieve_SeqS(item)) //0이 아니면(찾으면)
	{
		cout << "   <============ Singer FOUND !==========>" << endl;

		ItemType data;
		SongType song;
		m_List.ResetList();
		int curIndex;
		item.ResetList();
		while (1)
		{
			curIndex = item.GetNextItem(song);

			data.setsNumber(song.Sid);


			if (curIndex == -1)
			{
				break;
			}
			if (m_List.Retrieve_SeqS(data))
			{
				data.DisplayRecordOnScreen();

				cout << "   <====================================>" << endl;
			}
		}
		return 1;	//성공(1)을 리턴
	}
	else
	{
		cout << "   <======== Singer Not Found!==========>" << endl;

		return 0;	//실패(0)을 리턴
	}

}
/**
	*	@brief	사용자로부터 id, password 입력
	*	@pre	 list should be initialized.
	*	@post	search the record  by User.
	*	@return	회원가입하는데 성공하면 1값을 리턴, 그게 아니면 0을 리턴
	*/
int Application::registeruser()
{
	User preUser;
	preUser.setRecordFromKB();
	preUser.SetIsAdminFromKB();

	if (m_UserList.Retrieve_SeqS(preUser) == 1)
	{
		cout << "   <============이미 가입된 아이디입니다.=============>" << endl;
		return 0;
	}
	cout << "   <==================회원가입 완료!===================>" << endl;

	_getch();

	m_UserList.Add(preUser);
	return 0;
}
/**
	*	@brief	사용자로부터 새로운 id, password 입력
	*	@pre	 list should be initialized.
	*	@post	make the new record  by User.
	*	@return	회원가입하는데 성공하면 1값을 리턴, 그게 아니면 0을 리턴
	*/
int Application::login()
{
	User input, user;
	input.setRecordFromKB();
	user.setid(input.getid());
	m_UserList.Retrieve_SeqS(user);

	if (user.checklogin(input.getid(), input.getpassword())) {
		currentuser = user;
		menus = 16;
		selected = 1;

		return 1;
	}

	_getch();

	return 0;
}
/**
	*	@brief	Login driver.
	*	@pre	login is started.
	*	@post	login is finished.
	*/
int Application::getlogincommand()
{

	system("cls");

	int command;
	cout << endl << endl;
	cout << "   <-------------------------------------------------->" << endl;
	printMenuItem(1, "로그인");
	printMenuItem(2, "회원가입");
	/*
	cout << "   <---------------------1.로그인--------------------->" << endl;
	cout << "   <--------------------2.회원가입-------------------->" << endl;
	cout << "   <-------------------------------------------------->" << endl;
	cout << "   <---------사용하실 모드를 선택해주세요 ------------> ";
	*/
	cout << "   <-------------------------------------------------->" << endl;

	if (movebycursor())
		return selected;

	return 0;
}

void Application::printMenuItem(int no, const char* name)
{
	if (no == selected) {
		cout << "    > ";
	}
	else {
		cout << "      ";
	}

	cout << no << ". " << name << endl;
}

/**
	*	@brief	키보드에서 장르 이름을 읽고 list에서 이 장르 이름을 가진 모든 레코드를 찾아서 화면에 출력
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchByGenre()//장르의 이름을 키보드로부터 입력받아서 해당 장르의 모든 곡을 화면에 출력
{
	ItemType item;
	item.SetgenreFromKB(); //genre입력받는다.

	if (m_List.RetrieveByGenre(item)) //0이 아니면(찾으면)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout << "   <====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	else
	{
		cout << "   <======== Music Not Found!==========>" << endl;
		return 0;	//실패(0)을 리턴
	}
}

/**
	*	@brief	수정할 곡의 ID를 받아서 검색한 후에 존재하면 기존 정보를 키보드로부터 입력받은 새 정보를 치환
	*	@pre	 list should be initialized.
	*	@post	search the record  by sNumber.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchandReplace()//수정할 곡의 ID를 받아서 검색한 후에 존재하면 기존 정보를 키보드로부터 입력받은 새 정보를 치환 
{
	ItemType item;
	item.SetsNumberFromKB(); //id입력받는다.

	if (m_List.Retrieve_SeqS(item)) //0이 아니면(찾으면)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		cout << "   <=====해당 곡에 대한 새로운 정보를 입력해주세요=====>" << endl;

		ReplaceMusic(item);//입력된 사용자 고유번호에 대한 정보 교체
		cout << "   <==============수정 완료==============>" << endl;

		cout << "   <====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	else
	{
		cout << "   <======== Music Not Found!==========>" << endl;
		return 0;	//실패(0)을 리턴
	}
}

/**
	*	@brief	Add new record into playlist.
	*	@pre	list should be initialized.
	*	@post	new record is added into the playlist.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::AddSongToPL()
{
	ItemType input;
	input.SetsNumberFromKB();

	if (m_List.Retrieve_SeqS(input))
	{
		PlayItem item;
		item.SetRecord(input.getsNumber(), 0, plCount++);

		PlayItem dummy;

		currentuser.m_pList.Add(item);
	}
	return 0;
}

/**
	*	@brief	display the playlist.
	*	@pre	list should be initialized.
	*	@post	display tthe playlist.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::PlayIOAddTime()
{
	if (currentuser.m_pList.IsEmpty())
	{
		cout << "   <=============리스트가 비어있습니다=============>" << endl;
		return 0;
	}

	PlayItem item;
	ItemType song;

	int repeat = 1;
	while (repeat) {
		currentuser.m_pList.ResetList();
		while (currentuser.m_pList.GetNextItem(item) != -1)
		{

			item.SetNumPlay(item.GetNumPlay() + 1);
			currentuser.m_pList.Replace(item);

			song.setsNumber(item.GetSId());

			m_List.Retrieve_SeqS(song);
			song.DisplayRecordOnScreen();
			cout << "   <====================================>" << endl;

		}
		cout << "   계속 하시겠습니까? (1: 네, 0: 아니요)" << endl;
		cin >> repeat;
	}
	return 0;
}
/**
	*	@brief	display the playlist sorted by freq.
	*	@pre	list should be initialized.
	*	@post	display the sorted by freq playlist.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::PlayIOFreq()
{
	if (currentuser.m_pList.IsEmpty())
	{
		cout << "   <=============리스트가 비어있습니다=============>" << endl;
		return 0;
	}

	PlayItem item;
	PlayItemFreq freqItem;
	ItemType song;

	DoublyLinkedList<PlayItemFreq> freqOrder;

	currentuser.m_pList.ResetList();
	while (currentuser.m_pList.GetNextItem(item) != -1)
	{
		freqItem.SetSId(item.GetSId());
		freqItem.SetInTime(item.GetInTime());
		freqItem.SetNumPlay(item.GetNumPlay());
		freqOrder.Add(freqItem);
	}

	int repeat = 1;
	while (repeat) {
		freqOrder.ResetList();
		while (freqOrder.GetNextItem(freqItem) != -1) {
			freqItem.SetNumPlay(item.GetNumPlay() + 1);
			freqOrder.Replace(freqItem);

			song.setsNumber(freqItem.GetSId());

			m_List.Retrieve_SeqS(song);
			song.DisplayRecordOnScreen();
		}


		cout << "   <====================================>" << endl;

		cout << "   계속 하시겠습니까? (1: 네, 0: 아니요)" << endl;
		cin >> repeat;
	}

	freqOrder.ResetList();
	while (freqOrder.GetNextItem(freqItem) != -1) {
		item.SetSId(freqItem.GetSId());
		item.SetInTime(freqItem.GetInTime());
		item.SetNumPlay(freqItem.GetNumPlay());

		currentuser.m_pList.Replace(item);
	}

	return 0;
}

/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 playlist에서제거
	*	@pre	 인수 data에 있는 id가 playlist 내에 존재하는 값이어야 한다.
	*	@post	playlist 내에 해당 item이 제거된다.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
int Application::DeleteSongFrPL()
{
	ItemType input;
	input.SetsNumberFromKB();

	PlayItem item;
	item.SetSId(input.getsNumber());

	currentuser.m_pList.Delete(item);

	return 0;
}
/**
	*	@brief	Add new singer into singer list.
	*	@pre	list should be initialized.
	*	@post	new singer is added into the singer list.
	*	@return	return 1 if this function works well.
	*/
int Application::AddSinger()//새로운 가수를 추가
{
	SingerType item;
	item.setRecordFromKB();
	cout << "   <====================================>" << endl;
	m_SList.Add(item);

	return 1;
}
/**
	*	@brief	Add new song into song list.
	*	@pre	list should be initialized.
	*	@post	new song is added into the song list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::AddSong(ItemType item)//추가할 곡의 가수를 검색하고 가수가 존재하면 해당 가수의 songlist에 곡을 추가한다. 존재하지 않으면 가수를 추가하고 입력된 곡을 추가한다.
{

	SingerType singer;
	singer.setSingerName(item.getsinger());

	SongType song;
	song.Sid = item.getsNumber();
	song.Sname = item.getsName();

	if (m_SList.Retrieve_SeqS(singer))
	{
		singer.addSong(song);
		singer.SetCopied(true);
		m_SList.Replace(singer);
		return 1;
	}
	else
	{
		singer.setSingerGenderFromKB();
		singer.setSingerAgeFromKB();
		singer.addSong(song);
		singer.SetCopied(true);
		m_SList.Add(singer);
		return 0;
	}
}


/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
void Application::DisplayAllItem()//리스트에 있는 데이터 출력
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		cout << "   <====================================>" << endl;
		curIndex = m_List.GetNextItem(data);

	}
}
/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::OpenInFile(char* fileName)//파일 오픈용 함수
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}

/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::OpenOutFile(char* fileName)//파일에 있는 리코드를 리스트에 저장하기
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}
/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::ReadDataFromFile()//파일에 있는 리스트 데이터 불러오기
{
	if (!currentuser.isAdmin())
		return 0;

	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	//DisplayAllItem();

	return 1;
}
/**
*	@brief	Open a file as a write mode, and write all data into the file,
*	@pre	The file is not opened.
*	@post	the list is stored in the output file.
*	@return	return 1 if this function works well, otherwise 0.
*/
int Application::WriteDataToFile()// 파일에 리스트 데이터 저장하기
{
	if (!currentuser.isAdmin())
		return 0;

	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

