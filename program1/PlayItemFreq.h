#pragma once
#include <iostream>
using namespace std;

class PlayItemFreq
{
public:


	/**
		*	@brief	Display Id, numplay, intime on screen.
		*	@pre	id,numplay,intime is set.
		*	@post	id,numplay,intime    is on screen.
		*/
	void Displayitem()
	{
		cout << "ID : " << SId << endl;
		cout << "���� ����� Ƚ�� : " << NumPlay << endl;
		cout << "���� ���� : " << InTime << endl;
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
	bool operator==(const PlayItemFreq& item)
	{
		return SId == item.SId;
	}
	/**
*	@brief	Compare two play items by  numplay.
*	@pre	two play items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.numplay < data.numplay, 0 if not.
*/
	bool operator<(const PlayItemFreq& item)
	{
		return NumPlay < item.NumPlay;
	}
	/**
*	@brief	Compare two play items by  numplay.
*	@pre	two play items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.numplay > data.numplay, 0 if not.
*/
	bool operator>(const PlayItemFreq& item)
	{
		return NumPlay > item.NumPlay;
	}

private:
	string SId;//primary key
	int NumPlay;//���� ����� Ƚ��
	int InTime; //���� play list�� ���Ե� �ð�(�� ���������� ���� ������ ���)



};