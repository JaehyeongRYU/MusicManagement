#include "ItemType.h"
/**
	*	default constructor.
	*/
ItemType::ItemType()//6���� �����Ͱ� �ʱ�ȭ
{
	sType = -1;
	sName = "";
	sWriter = "";
	singer = "";
	genre = -1;
	sNumber = "";
}
/**
	*	destructor.
	*/
ItemType::~ItemType()
{
}
/**
*	@brief	Get song type.
*	@pre	song type is set.
*	@post	none.
*	@return	song type.
*/
int ItemType::getsType()//s_Type�� ��ȯ
{
	return sType;
}
/*
	*	@brief	Get song name.
	*	@pre	song name is set.
	*	@post	none.
	*	@return	song name.
	*
*/
string ItemType::getsName()//sName�� ��ȯ
{
	return sName;
}
/**
	*	@brief	Get song Writer
	*	@pre	song writer is set.
	*	@post	none.
	*	@return	song writer.
	*/
string ItemType::getsWriter()//sWriter�� ��ȯ
{
	return sWriter;
}
/**
	*	@brief	Get singer
	*	@pre	song singer is set.
	*	@post	none.
	*	@return	song singer.
	*/
string ItemType::getsinger()//singer�� ��ȯ
{
	return singer;
}
/**
	*	@brief	Get song genre
	*	@pre	song genre is set.
	*	@post	none.
	*	@return	song genre.
	*/
int ItemType::getgenre()//genre�� ��ȯ
{
	return genre;
}
/**
	*	@brief	Get song Number
	*	@pre	song Number is set.
	*	@post	none.
	*	@return	song Number.
	*/
string ItemType::getsNumber()//sNumber�� ��ȯ
{
	return sNumber;
}
/**
	*	@brief	Set song type.
	*	@pre	none.
	*	@post	song type is set.
	*	@param	in song type.
	*/
void ItemType::setsType(int insType)//sType�� insType ����
{
	sType = insType;
}
/**
	*	@brief	Set song name.
	*	@pre	none.
	*	@post	song name is set.
	*	@param	in song name.
	*/
void ItemType::setsName(string insName)//sName�� insName ����
{
	sName = insName;
}
/**
	*	@brief	Set song writer.
	*	@pre	none.
	*	@post	song writer is set.
	*	@param	in song writer.
	*/
void ItemType::setsWriter(string insWriter)//sWriter�� insWriter ����
{
	sWriter = insWriter;
}
/**
	*	@brief	Set song singer.
	*	@pre	none.
	*	@post	song singer is set.
	*	@param	in song singer.
	*/
void ItemType::setsinger(string insinger)//singer�� insinger ����
{
	singer = insinger;
}
/**
	*	@brief	Set song genre.
	*	@pre	none.
	*	@post	song genre is set.
	*	@param	in song genre.
	*/
void ItemType::setgenre(int ingenre)//genre�� ingenre ����
{
	genre = ingenre;
}
/**
	*	@brief	Set song number.
	*	@pre	none.
	*	@post	song number is set.
	*	@param	in song number.
	*/
void ItemType::setsNumber(string insNumber)//sNumber�� insNumber ����
{
	sNumber = insNumber;
}
/**
*	@brief	Set song record.
*	@pre	none.
*	@post	song record is set.
*	@param	insType	song type.
*	@param	insName	song name.
*	@param	insWriter song writer.
*	@param	insinger song singer.
*	@param	ingenre song genre.
*	@param	insNumber song Number.

*/
void ItemType::setRecord(int insType, string insName, string insWriter, string insinger, int ingenre, string insNumber)//Set�Լ� 6�� ȣ��
{
	setsType(insType);
	setsName(insName);
	setsWriter(insWriter);
	setsinger(insinger);
	setgenre(ingenre);
	setsNumber(insNumber);
}
/**
	*	@brief	Display song Type on screen.
	*	@pre	song type is set.
	*	@post	song type is on screen.
	*/
void ItemType::DisplaysTypeOnScreen()//ȭ�鿡 sType ���
{
	cout << "Song Type : " << sType << endl;
}
/**
	*	@brief	Display song name on screen.
	*	@pre	song name is set.
	*	@post	song name is on screen.
	*/
void ItemType::DisplaysNameOnScreen()//ȭ�鿡 sName ���
{
	cout << "Song Name : " << sName << endl;
}
/**
	*	@brief	Display song writer on screen.
	*	@pre	song writer is set.
	*	@post	song writer is on screen.
	*/
void ItemType::DisplaysWriterOnScreen()//ȭ�鿡 sWriter ���
{
	cout << "Song Writer : " << sWriter << endl;
}
/**
	*	@brief	Display song singer on screen.
	*	@pre	song singer is set.
	*	@post	song singer is on screen.
	*/
void ItemType::DisplaysingerOnScreen()//ȭ�鿡 singer ���
{
	cout << "Song singer : " << singer << endl;
}
/**
	*	@brief	Display song genre on screen.
	*	@pre	song genre is set.
	*	@post	song genre is on screen.
	*/
void ItemType::DisplaygenreOnScreen()//ȭ�鿡 genre ���
{
	cout << "Song genre : " << genre << endl;
}/**
	*	@brief	Display song Number on screen.
	*	@pre	song Number is set.
	*	@post	song Number is on screen.
	*/
void ItemType::DisplaysNumberOnScreen()//ȭ�鿡 sNumber ���
{
	cout << "Song Number : " << sNumber << endl;
}
/**
*	@brief	Display an song record on screen.
*	@pre	song record is set.
*	@post	song record is on screen.
*/
void ItemType::DisplayRecordOnScreen()//ȭ�鿡 ���ڵ� ���
{
	DisplaysTypeOnScreen();
	DisplaysNameOnScreen();
	DisplaysWriterOnScreen();
	DisplaysingerOnScreen();
	DisplaygenreOnScreen();
	DisplaysNumberOnScreen();

}
/**
	*	@brief	Set song type from keyboard.
	*	@pre	none.
	*	@post	song type is set.
	*/
void ItemType::SetsTypeFromKB()//����ڷκ��� sType �Է� ����
{
	cout << "Song Type : ";
	cin >> sType; //song type �Է�
}
/**
	*	@brief	Set song name from keyboard.
	*	@pre	none.
	*	@post	song name is set.
	*/
void ItemType::SetsNameFromKB()//����ڷκ��� sName �Է� ����
{
	cout << "Song Name : ";
	cin >> sName; //song name �Է�
}
/**
	*	@brief	Set song writer from keyboard.
	*	@pre	none.
	*	@post	song writer is set.
	*/
void ItemType::SetsWriterFromKB()//����ڷκ��� sWriter �Է� ����
{
	cout << "Song Writer : ";
	cin >> sWriter; //song writer �Է�
}
/**
	*	@brief	Set song singer from keyboard.
	*	@pre	none.
	*	@post	song singer is set.
	*/
void ItemType::SetsingerFromKB()//����ڷκ��� singer �Է� ����
{
	cout << "Song Singer : ";
	cin >> singer; //song singer �Է�
}
/**
	*	@brief	Set song genre from keyboard.
	*	@pre	none.
	*	@post	song genre is set.
	*/
void ItemType::SetgenreFromKB()//����ڷκ��� genre �Է� ����
{
	cout << "Song Genre : ";
	cin >> genre; //song genre �Է�
}
/**
	*	@brief	Set song Number from keyboard.
	*	@pre	none.
	*	@post	song Number is set.
	*/
void ItemType::SetsNumberFromKB()//����ڷκ��� sNumber �Է� ����
{
	cout << "Song Number : ";
	cin >> sNumber; //song Number �Է�
}
/**
*	@brief	Set song record from keyboard.
*	@pre	none.
*	@post	song record is set.
*/
void ItemType::SetRecordFromKB()//����� �Է� �Լ� 6�� ȣ��
{
	SetsTypeFromKB();
	SetsNameFromKB();
	SetsWriterFromKB();
	SetsingerFromKB();
	SetgenreFromKB();
	SetsNumberFromKB();
}

/**
*	@brief	Read a record from file.
*	@pre	the target file is opened.
*	@post	song record is set.
*	@param	fin	file descriptor.
*	@return	return 1 if this function works well, otherwise 0.
*/
int ItemType::ReadDataFromFile(ifstream& fin)//���Ͽ��� ������ �д� �Լ�
{
	fin >> sType;//���Ͽ��� sType �б�
	fin >> sName;//���Ͽ��� sName �б�
	fin >> sWriter;//���Ͽ��� sWriter �б�
	fin >> singer;//���Ͽ��� singer �б�
	fin >> genre;//���Ͽ��� genre �б�
	fin >> sNumber;//���Ͽ��� sNnumber �б�

	return 1;
}
/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new song record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int ItemType::WriteDataToFile(ofstream& fout)//���Ͽ��� ������ �Է� �Լ�
{
	fout << endl;
	fout << sType << " ";//���Ͽ��� sType ���
	fout << sName << " ";//���Ͽ��� sName ���
	fout << sWriter << " ";//���Ͽ��� sWriter ���
	fout << singer << " ";//���Ͽ��� singer ���
	fout << genre << " ";//���Ͽ��� genre ���
	fout << sNumber << " ";//���Ͽ��� sNumber ���

	return 1;
}
/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
RelationType ItemType::Compare(const ItemType& data)//primary key(ID)�� �������� ���� ������ ���ϴ� �Լ�
{
	if (this->sNumber > data.sNumber)
		return GREATER;
	else if (this->sNumber < data.sNumber)
		return LESS;
	else
		return EQUAL;
}
/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item genre.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.genre < data.genre,
	*			return GREATER if this.genre > data.genre then,
	*			otherwise return EQUAL.
	*/
RelationType ItemType::CompareByGenre(const ItemType& data)//�帣�� �������� �л� ������ ���ϴ� �Լ�
{
	if (this->genre > data.genre)
		return GREATER;
	else if (this->genre < data.genre)
		return LESS;
	else
		return EQUAL;
}
/**
*	@brief	Compare two item types by item id.
*	@pre	two item types should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id > data.id, 0 if not.
*/
bool ItemType::operator>(ItemType item)
{
	return (this->getsNumber() > item.getsNumber());
}
/**
*	@brief	Compare two item types by item id.
*	@pre	two item types should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id == data.id, 0 if not.
*/
bool ItemType::operator==(ItemType item)
{
	return (this->getsNumber() == item.getsNumber());
}
