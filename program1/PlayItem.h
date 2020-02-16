#pragma once
#include <iostream>
#include "ItemType.h"

using namespace std;

class PlayItem
{
public:


	/**
		*	@brief	Display Id, numplay, intime on screen.
		*	@pre	id,numplay,intime is set.
		*	@post	id,numplay,intime    is on screen.
		*/
	void Displayitem() {
		cout << "ID : " << SId << endl;
		cout << "���� ����� Ƚ�� : " << NumPlay << endl;
		cout << "���� ���� : " << InTime << endl;
	}
	/**
	*	Compare two play items.
	*	@brief	Compare two item types by item id.
	*	@pre	two play item should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType Compare(const PlayItem& data)
	{
		if (this->SId > data.SId)
			return GREATER;
		else if (this->SId < data.SId)
			return LESS;
		else
			return EQUAL;
	}
	/**
	*	@brief	Get song ID
	*	@pre	song ID is set.
	*	@post	none.
	*	@return	song ID.
	*/
	string GetSId()
	{
		return SId;
	}
	/**
	*	@brief	Set song ID.
	*	@pre	none.
	*	@post	song ID is set.
	*	@param	in song ID.
	*/
	void SetSId(string id)
	{
		SId = id;
	}
	/**
	*	@brief	Get Num Play
	*	@pre	Num Play is set.
	*	@post	none.
	*	@return	Num Play.
	*/
	int GetNumPlay()
	{
		return NumPlay;
	}
	/**
	*	@brief	Set Num Play.
	*	@pre	none.
	*	@post	Num Play is set.
	*	@param	in Num Play.
	*/
	void SetNumPlay(int plays)
	{
		NumPlay = plays;
	}
	/**
*	@brief	Get InTime
*	@pre	InTime is set.
*	@post	none.
*	@return	InTime.
*/
	int GetInTime()
	{
		return InTime;
	}
	/**
*	@brief	Set In Time.
*	@pre	none.
*	@post	In Time is set.
*	@param	in time.
*/
	void SetInTime(int time)
	{
		InTime = time;
	}
	/**
	*	@brief	Set song record.
	*	@pre	none.
	*	@post	song record is set.
	*	@param	inid	song id.
	*	@param	inplays	plays.
	*	@param	intime time.
	*/
	void SetRecord(string id, int plays, int time)
	{
		SetSId(id);
		SetNumPlay(plays);
		SetInTime(time);
	}
	/**
*	@brief	Compare two play items by  id.
*	@pre	two play items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id = data.id, 0 if not.
*/
	bool operator==(const PlayItem& item) {
		return SId == item.SId;
	}
	/**
*	@brief	Compare two play items by  intime.
*	@pre	two play items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.intime < data.intime, 0 if not.
*/
	bool operator<(const PlayItem& item) {
		return InTime < item.InTime;
	}
	/**
*	@brief	Compare two play items by  intime.
*	@pre	two play items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.intime > data.intime, 0 if not.
*/
	bool operator>(const PlayItem& item) {
		return InTime > item.InTime;
	}

private:
	string SId;//primary key
	int NumPlay;//���� ����� Ƚ��
	int InTime; //���� play list�� ���Ե� �ð�(�� ���������� ���� ������ ���)



};