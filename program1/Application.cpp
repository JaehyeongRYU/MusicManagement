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
		//	cout << "   <============1 �Ǵ� 2 �� �Է����ּ���!!!============>" << endl;
		//else
		//	cout << "   <=======�߸��� �Է��Դϴ�! �ٽ� �Է����ּ���!=======>" << endl;
	}
}

/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
void Application::RunUser()//���α׷� ����
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
int Application::GetCommand()//��� �޴� �Լ�
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
int Application::AddItem()//���� ������ �Է¹޾� ����Ʈ�� �߰�
{
	if (!currentuser.isAdmin())
	{
		cout << "   <==========�����ڸ� ������ �� �ֽ��ϴ�.==========>" << endl;

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
	*	@brief	���������� �˻��ؼ� �ش� ������ ���
	*	@pre	 list should be initialized.
	*	@post	search the record  by Id.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchById_SequenS()//���������� �˻��ؼ� �ش� ������ ���
{
	ItemType item;
	item.SetsNumberFromKB(); //id�Է¹޴´�.

	if (m_List.Retrieve_SeqS(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << "   <======== Music Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
}


/**
	*	@brief	Id�Է¹޾� �ش� �����͸� ����Ʈ���� ����
	*	@pre	 list should be initialized.
	*	@post	delete the record which is found by Id.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::DeleteItem()//Id�Է¹޾� �ش� �����͸� ����Ʈ���� ����
{
	if (!currentuser.isAdmin())
		return 0;

	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	ItemType item;
	item.SetsNumberFromKB();

	m_List.Delete(item);

	if (pre > m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "   <========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "   <========DELETE FAIL !=======>" << endl;
	return 0;
}
/**
	*	@brief	Ű���忡�� �̸��� �а� list���� �� �̸��� ���� ��� ���ڵ带 ã�Ƽ� ȭ�鿡 ���
	*	@pre	 list should be initialized.
	*	@post	search the record  by Name.
	*	@return	1���� ����
	*/
int Application::SearchBysName()//Ű���忡�� �̸��� �а� list���� �� �̸��� ���� ��� ���ڵ带 ã�Ƽ� ȭ�鿡 ���
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
	*	@brief	Ű���忡�� ���� �̸��� �а� list���� �� ���� �̸��� ���� ��� ���ڵ带 ã�Ƽ� ȭ�鿡 ���
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	1���� ����
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
	*	@brief	Ű���忡�� ���� �̸��� �а� �ش� ������ �θ� �뷡�� �˻��ؼ� ���
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	�˻��ϴµ� �����ϸ� 1���� ����, �װ� �ƴϸ� 0�� ����
	*/
int Application::SearchBySingerPL()////singerList���� ������ �˻��ϰ� �ش� ������ �θ� ��� ���� �ڼ��� ������ ȭ�鿡 ����Ѵ�
{
	SingerType item;
	item.setSingerNameFromKB();

	if (m_SList.Retrieve_SeqS(item)) //0�� �ƴϸ�(ã����)
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
		return 1;	//����(1)�� ����
	}
	else
	{
		cout << "   <======== Singer Not Found!==========>" << endl;

		return 0;	//����(0)�� ����
	}

}
/**
	*	@brief	����ڷκ��� id, password �Է�
	*	@pre	 list should be initialized.
	*	@post	search the record  by User.
	*	@return	ȸ�������ϴµ� �����ϸ� 1���� ����, �װ� �ƴϸ� 0�� ����
	*/
int Application::registeruser()
{
	User preUser;
	preUser.setRecordFromKB();
	preUser.SetIsAdminFromKB();

	if (m_UserList.Retrieve_SeqS(preUser) == 1)
	{
		cout << "   <============�̹� ���Ե� ���̵��Դϴ�.=============>" << endl;
		return 0;
	}
	cout << "   <==================ȸ������ �Ϸ�!===================>" << endl;

	_getch();

	m_UserList.Add(preUser);
	return 0;
}
/**
	*	@brief	����ڷκ��� ���ο� id, password �Է�
	*	@pre	 list should be initialized.
	*	@post	make the new record  by User.
	*	@return	ȸ�������ϴµ� �����ϸ� 1���� ����, �װ� �ƴϸ� 0�� ����
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
	printMenuItem(1, "�α���");
	printMenuItem(2, "ȸ������");
	/*
	cout << "   <---------------------1.�α���--------------------->" << endl;
	cout << "   <--------------------2.ȸ������-------------------->" << endl;
	cout << "   <-------------------------------------------------->" << endl;
	cout << "   <---------����Ͻ� ��带 �������ּ��� ------------> ";
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
	*	@brief	Ű���忡�� �帣 �̸��� �а� list���� �� �帣 �̸��� ���� ��� ���ڵ带 ã�Ƽ� ȭ�鿡 ���
	*	@pre	 list should be initialized.
	*	@post	search the record  by Singer.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchByGenre()//�帣�� �̸��� Ű����κ��� �Է¹޾Ƽ� �ش� �帣�� ��� ���� ȭ�鿡 ���
{
	ItemType item;
	item.SetgenreFromKB(); //genre�Է¹޴´�.

	if (m_List.RetrieveByGenre(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout << "   <====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	else
	{
		cout << "   <======== Music Not Found!==========>" << endl;
		return 0;	//����(0)�� ����
	}
}

/**
	*	@brief	������ ���� ID�� �޾Ƽ� �˻��� �Ŀ� �����ϸ� ���� ������ Ű����κ��� �Է¹��� �� ������ ġȯ
	*	@pre	 list should be initialized.
	*	@post	search the record  by sNumber.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::SearchandReplace()//������ ���� ID�� �޾Ƽ� �˻��� �Ŀ� �����ϸ� ���� ������ Ű����κ��� �Է¹��� �� ������ ġȯ 
{
	ItemType item;
	item.SetsNumberFromKB(); //id�Է¹޴´�.

	if (m_List.Retrieve_SeqS(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "   <============ Music FOUND !==========>" << endl;
		cout << "   <=====�ش� � ���� ���ο� ������ �Է����ּ���=====>" << endl;

		ReplaceMusic(item);//�Էµ� ����� ������ȣ�� ���� ���� ��ü
		cout << "   <==============���� �Ϸ�==============>" << endl;

		cout << "   <====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	else
	{
		cout << "   <======== Music Not Found!==========>" << endl;
		return 0;	//����(0)�� ����
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
		cout << "   <=============����Ʈ�� ����ֽ��ϴ�=============>" << endl;
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
		cout << "   ��� �Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�)" << endl;
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
		cout << "   <=============����Ʈ�� ����ֽ��ϴ�=============>" << endl;
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

		cout << "   ��� �Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�)" << endl;
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
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� playlist��������
	*	@pre	 �μ� data�� �ִ� id�� playlist ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	playlist ���� �ش� item�� ���ŵȴ�.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
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
int Application::AddSinger()//���ο� ������ �߰�
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
int Application::AddSong(ItemType item)//�߰��� ���� ������ �˻��ϰ� ������ �����ϸ� �ش� ������ songlist�� ���� �߰��Ѵ�. �������� ������ ������ �߰��ϰ� �Էµ� ���� �߰��Ѵ�.
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
void Application::DisplayAllItem()//����Ʈ�� �ִ� ������ ���
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
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
int Application::OpenInFile(char* fileName)//���� ���¿� �Լ�
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
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
int Application::OpenOutFile(char* fileName)//���Ͽ� �ִ� ���ڵ带 ����Ʈ�� �����ϱ�
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}
/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int Application::ReadDataFromFile()//���Ͽ� �ִ� ����Ʈ ������ �ҷ�����
{
	if (!currentuser.isAdmin())
		return 0;

	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	//DisplayAllItem();

	return 1;
}
/**
*	@brief	Open a file as a write mode, and write all data into the file,
*	@pre	The file is not opened.
*	@post	the list is stored in the output file.
*	@return	return 1 if this function works well, otherwise 0.
*/
int Application::WriteDataToFile()// ���Ͽ� ����Ʈ ������ �����ϱ�
{
	if (!currentuser.isAdmin())
		return 0;

	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
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

