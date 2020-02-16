#include "SingerType.h"

/**
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.id == data.id, 0 if not.
	*/
bool operator==(const SongType& a, const SongType& b)
{
	return a.Sid == b.Sid;
}
/**
*	@brief	Compare two item types by item id.
*	@pre	two item types should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id > data.id, 0 if not.
*/
bool operator>(const SongType& a, const SongType& b)
{
	return a.Sid > b.Sid;
}
/*
	*	@brief	Get singer name.
	*	@pre	singer name is set.
	*	@post	none.
	*	@return	singer name.
	*
*/
string SingerType::getSingerName()
{
	return SingerName;
}
/*
	*	@brief	Get singer age.
	*	@pre	singer age is set.
	*	@post	none.
	*	@return	singer age.
	*
*/
int SingerType::getSingerAge()
{
	return SingerAge;
}
/*
	*	@brief	Get singer gender.
	*	@pre	singer gender is set.
	*	@post	none.
	*	@return	singer gender.
	*
*/
int SingerType::getSingerGender()
{
	return SingerGender;
}
/**
	*	@brief	Set singer name.
	*	@pre	none.
	*	@post	singer name is set.
	*	@param	in singer name.
	*/
void SingerType::setSingerName(string inSName)
{
	SingerName = inSName;
}
/**
	*	@brief	Set singer age
	*	@pre	none.
	*	@post	singer age is set.
	*	@param	in singer age.
	*/
void SingerType::setSingerAge(int inSAge)
{
	SingerAge = inSAge;
}
/**
	*	@brief	Set singer gender
	*	@pre	none.
	*	@post	singer gender is set.
	*	@param	in singer gender.
	*/
void SingerType::setSingerGender(int inSGender)
{
	SingerGender = inSGender;
}
/**
*	@brief	Set singer record.
*	@pre	none.
*	@post	singer record is set.
*	@param	insName	singer name.
*	@param	insage	singer age.
*	@param	insgender singer gender.

*/
void SingerType::setRecord(string inSName, int inSAge, int inSGender)
{
	setSingerName(inSName);
	setSingerAge(inSAge);
	setSingerGender(inSGender);
}
/**
	*	@brief	Set singer name from keyboard.
	*	@pre	none.
	*	@post	singer name is set.
	*/
void SingerType::setSingerNameFromKB()
{
	cout << "Singer Name : ";
	cin >> SingerName; //singer name 입력
}
/**
	*	@brief	Set singer age from keyboard.
	*	@pre	none.
	*	@post	singer age is set.
	*/
void SingerType::setSingerAgeFromKB()
{
	cout << "Singer Age : ";
	cin >> SingerAge; //singer age 입력
}
/**
	*	@brief	Set singer gender from keyboard.
	*	@pre	none.
	*	@post	singer gender is set.
	*/
void SingerType::setSingerGenderFromKB()
{
	cout << "Singer Gender(남자는 1, 여자는 0을 입력해주세요) : ";
	cin >> SingerGender; //singer Gender 입력
}
/**
*	@brief	Set singer record from keyboard.
*	@pre	none.
*	@post	singer record is set.
*/
void SingerType::setRecordFromKB()
{
	setSingerNameFromKB();
	setSingerAgeFromKB();
	setSingerGenderFromKB();
}

/**
	*	@brief	Add new record into song list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the song list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
void SingerType::addSong(SongType& song)
{
	songList.Add(song);
}
/**
	*	@brief	Initialize list iterator.
	*	@pre	 list should be initialized.
	*	@post	iterator is reset.
	*/
void SingerType::ResetList()
{
	songList.ResetList();
}
/**
*	@brief	move list iterator to the next item in list and get that item.
*	@pre	 list and list iterator should not be initialized.
*	@post	iterator is moved to next item.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, oterwise return -1.
*/
int SingerType::GetNextItem(SongType& item)
{
	return songList.GetNextItem(item);
}
/**
	*	@brief	node pointer값 -> copied 변수.
	*	@post    node poiner의 값이 copied에 넣어진다.
	*	@param	node pointer값이 소멸자에서 사라지는걸 방지하고자 만든 copied 변수.
	*/
void SingerType::SetCopied(bool copied)
{
	songList.SetCopied(copied);
}
/**
	*	@brief	Compare two item types by singer name.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Singername == data.Singername, 0 if not.
	*/
bool SingerType::operator==(SingerType& singer)
{
	return (this->getSingerName() == singer.getSingerName());
}
/**
*	@brief	Compare two item types by item.
*	@pre	two item types should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.Singername > data.Singername, 0 if not.
*/
bool SingerType::operator>(SingerType& singer)
{
	return (this->getSingerName() > singer.getSingerName());
}
/**
	*	@brief	Set song id from keyboard.
	*	@pre	none.
	*	@post	song id is set.
	*/
void SongType::setSongIdFromKB()
{
	cout << "Song ID : ";
	cin >> Sid; //song ID 입력
}
/**
	*	@brief	Set song name from keyboard.
	*	@pre	none.
	*	@post	song name is set.
	*/
void SongType::setSongnameFromKB()
{
	cout << "Song Name : ";
	cin >> Sname; //song Name 입력
}
