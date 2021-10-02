#include"inc/system.h"

System* System::instance = nullptr;

System::System()
{

}

System* System::get_instance()
{
	if(instance == nullptr)
	{
		instance = new System();
	}

	return instance;
}

bool System::signup(string username, string password)
{
	accounts[username] = password;
	return true;
}

bool System::check_username_availability(string username)
{
	return (accounts.count(username));
}

bool System::check_login_credentials(string username, string password)
{
	return (password == accounts[username]);
}