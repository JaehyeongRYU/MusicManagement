#include "ItemType.h"
/**
	*	default constructor.
	*/
ItemType::ItemType()//6개의 데이터값 초기화
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
int ItemType::getsType()//s_Type값 반환
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
string ItemType::getsName()//sName값 반환
{
	return sName;
}
/**
	*	@brief	Get song Writer
	*	@pre	song writer is set.
	*	@post	none.
	*	@return	song writer.
	*/
string ItemType::getsWriter()//sWriter값 반환
{
	return sWriter;
}
/**
	*	@brief	Get singer
	*	@pre	song singer is set.
	*	@post	none.
	*	@return	song singer.
	*/
string ItemType::getsinger()//singer값 반환
{
	return singer;
}
/**
	*	@brief	Get song genre
	*	@pre	song genre is set.
	*	@post	none.
	*	@return	song genre.
	*/
int ItemType::getgenre()//genre값 반환
{
	return genre;
}
/**
	*	@brief	Get song Number
	*	@pre	song Number is set.
	*	@post	none.
	*	@return	song Number.
	*/
string ItemType::getsNumber()//sNumber값 반환
{
	return sNumber;
}
/**
	*	@brief	Set song type.
	*	@pre	none.
	*	@post	song type is set.
	*	@param	in song type.
	*/
void ItemType::setsType(int insType)//sType에 insType 대입
{
	sType = insType;
}
/**
	*	@brief	Set song name.
	*	@pre	none.
	*	@post	song name is set.
	*	@param	in song name.
	*/
void ItemType::setsName(string insName)//sName에 insName 대입
{
	sName = insName;
}
/**
	*	@brief	Set song writer.
	*	@pre	none.
	*	@post	song writer is set.
	*	@param	in song writer.
	*/
void ItemType::setsWriter(string insWriter)//sWriter에 insWriter 대입
{
	sWriter = insWriter;
}
/**
	*	@brief	Set song singer.
	*	@pre	none.
	*	@post	song singer is set.
	*	@param	in song singer.
	*/
void ItemType::setsinger(string insinger)//singer에 insinger 대입
{
	singer = insinger;
}
/**
	*	@brief	Set song genre.
	*	@pre	none.
	*	@post	song genre is set.
	*	@param	in song genre.
	*/
void ItemType::setgenre(int ingenre)//genre에 ingenre 대입
{
	genre = ingenre;
}
/**
	*	@brief	Set song number.
	*	@pre	none.
	*	@post	song number is set.
	*	@param	in song number.
	*/
void ItemType::setsNumber(string insNumber)//sNumber에 insNumber 대입
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
void ItemType::setRecord(int insType, string insName, string insWriter, string insinger, int ingenre, string insNumber)//Set함수 6개 호출
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
void ItemType::DisplaysTypeOnScreen()//화면에 sType 출력
{
	cout << "Song Type : " << sType << endl;
}
/**
	*	@brief	Display song name on screen.
	*	@pre	song name is set.
	*	@post	song name is on screen.
	*/
void ItemType::DisplaysNameOnScreen()//화면에 sName 출력
{
	cout << "Song Name : " << sName << endl;
}
/**
	*	@brief	Display song writer on screen.
	*	@pre	song writer is set.
	*	@post	song writer is on screen.
	*/
void ItemType::DisplaysWriterOnScreen()//화면에 sWriter 출력
{
	cout << "Song Writer : " << sWriter << endl;
}
/**
	*	@brief	Display song singer on screen.
	*	@pre	song singer is set.
	*	@post	song singer is on screen.
	*/
void ItemType::DisplaysingerOnScreen()//화면에 singer 출력
{
	cout << "Song singer : " << singer << endl;
}
/**
	*	@brief	Display song genre on screen.
	*	@pre	song genre is set.
	*	@post	song genre is on screen.
	*/
void ItemType::DisplaygenreOnScreen()//화면에 genre 출력
{
	cout << "Song genre : " << genre << endl;
}/**
	*	@brief	Display song Number on screen.
	*	@pre	song Number is set.
	*	@post	song Number is on screen.
	*/
void ItemType::DisplaysNumberOnScreen()//화면에 sNumber 출력
{
	cout << "Song Number : " << sNumber << endl;
}
/**
*	@brief	Display an song record on screen.
*	@pre	song record is set.
*	@post	song record is on screen.
*/
void ItemType::DisplayRecordOnScreen()//화면에 레코드 출력
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
void ItemType::SetsTypeFromKB()//사용자로부터 sType 입력 받음
{
	cout << "Song Type : ";
	cin >> sType; //song type 입력
}
/**
	*	@brief	Set song name from keyboard.
	*	@pre	none.
	*	@post	song name is set.
	*/
void ItemType::SetsNameFromKB()//사용자로부터 sName 입력 받음
{
	cout << "Song Name : ";
	cin >> sName; //song name 입력
}
/**
	*	@brief	Set song writer from keyboard.
	*	@pre	none.
	*	@post	song writer is set.
	*/
void ItemType::SetsWriterFromKB()//사용자로부터 sWriter 입력 받음
{
	cout << "Song Writer : ";
	cin >> sWriter; //song writer 입력
}
/**
	*	@brief	Set song singer from keyboard.
	*	@pre	none.
	*	@post	song singer is set.
	*/
void ItemType::SetsingerFromKB()//사용자로부터 singer 입력 받음
{
	cout << "Song Singer : ";
	cin >> singer; //song singer 입력
}
/**
	*	@brief	Set song genre from keyboard.
	*	@pre	none.
	*	@post	song genre is set.
	*/
void ItemType::SetgenreFromKB()//사용자로부터 genre 입력 받음
{
	cout << "Song Genre : ";
	cin >> genre; //song genre 입력
}
/**
	*	@brief	Set song Number from keyboard.
	*	@pre	none.
	*	@post	song Number is set.
	*/
void ItemType::SetsNumberFromKB()//사용자로부터 sNumber 입력 받음
{
	cout << "Song Number : ";
	cin >> sNumber; //song Number 입력
}
/**
*	@brief	Set song record from keyboard.
*	@pre	none.
*	@post	song record is set.
*/
void ItemType::SetRecordFromKB()//사용자 입력 함수 6개 호출
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
int ItemType::ReadDataFromFile(ifstream& fin)//파일에서 데이터 읽는 함수
{
	fin >> sType;//파일에서 sType 읽기
	fin >> sName;//파일에서 sName 읽기
	fin >> sWriter;//파일에서 sWriter 읽기
	fin >> singer;//파일에서 singer 읽기
	fin >> genre;//파일에서 genre 읽기
	fin >> sNumber;//파일에서 sNnumber 읽기

	return 1;
}
/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new song record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
int ItemType::WriteDataToFile(ofstream& fout)//파일에서 데이터 입력 함수
{
	fout << endl;
	fout << sType << " ";//파일에서 sType 출력
	fout << sName << " ";//파일에서 sName 출력
	fout << sWriter << " ";//파일에서 sWriter 출력
	fout << singer << " ";//파일에서 singer 출력
	fout << genre << " ";//파일에서 genre 출력
	fout << sNumber << " ";//파일에서 sNumber 출력

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
RelationType ItemType::Compare(const ItemType& data)//primary key(ID)를 기준으로 음악 정보를 비교하는 함수
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
RelationType ItemType::CompareByGenre(const ItemType& data)//장르를 기준으로 학생 정보를 비교하는 함수
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
