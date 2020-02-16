#include "User.h"
/**
*	@brief	Set  userID.
*	@pre	none.
*	@post	user ID is set.
*	@param	in user ID.
*/
void User::setid(string inid)
{
	id = inid;
}
/**
*	@brief	Set  user password.
*	@pre	none.
*	@post	user password is set.
*	@param	in user password.
*/
void User::setpassword(string inpassword)
{
	password = inpassword;
}
/**
*	@brief	Get user ID
*	@pre	song user ID is set.
*	@post	none.
*	@return	user ID.
*/
string User::getid()
{
	return id;
}
/**
*	@brief	Get user password
*	@pre	song user word is set.
*	@post	none.
*	@return	user password.
*/
string User::getpassword()
{
	return password;
}
/**
*	@brief	Compare id, password.
*	@pre	two userlist should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id = nid and this.password = npassword, 0 if not.
*/
int User::checklogin(string nId, string nPassword)
{
	if (id == nId && password == nPassword)
		return 1;
	else
		return 0;
}
/**
*	@brief	Set user record from keyboard.
*	@pre	none.
*	@post	user record is set.
*/
void User::setRecordFromKB()
{
	SetIdFromKB();
	SetPasswordFromKB();
}
/**
*	@brief	Set user id from keyboard.
*	@pre	none.
*	@post	user id is set.
*/
void User::SetIdFromKB()
{
	cout << "   아이디를 입력해주세요 : ";
	cin >> id;
}
/**
*	@brief	Set user password from keyboard.
*	@pre	none.
*	@post	user password is set.
*/
void User::SetPasswordFromKB()
{
	cout << "   비밀번호를 입력해주세요 : ";
	cin >> password;
}
/**
*	@brief	Set isAdmin from keyboard.
*	@pre	none.
*	@post	IsAdmin is set.
*/
void User::SetIsAdminFromKB()
{
	cout << "   일반회원이면 1, 관리자면 2를 입력해주세요 : ";
	int nerd;
	cin >> nerd;
	admin = nerd == 2;
}
/**
*	@brief. return admin
*	@pre	none.
*	@post	return admin.
*/
bool User::isAdmin()
{
	return admin;
}
/**
*	@brief	Compare two user items by id.
*	@pre	two user items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id > data.id, 0 if not.
*/
bool User::operator>(User item)
{
	return (this->getid() > item.getid());
}
/**
*	@brief	Compare two user items by  id.
*	@pre	two user items should be initialized.
*	@param	data	target item for comparing.
*	@return	return 1 if this.id = data.id, 0 if not.
*/
bool User::operator==(User item)
{
	return (this->getid() == item.getid());
}