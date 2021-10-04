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
	cout << "COUNT :: " << accounts.count(username) << endl;
	return (accounts.count(username));
}

bool System::check_login_credentials(string username, string password)
{
	bool status = false;
	try 
	{
    	status = (accounts.at(username) == password);      // vector::at throws an out-of-range
  	}
  	catch (const std::out_of_range& oor) {
    	std::cerr << "Out of Range error: " << oor.what() << '\n';
  	}
	return status;
}

void System::set_login_status(string username, bool status)
{
	login_status[username] = status;
}

int System::get_current_balance(string username)
{
	try
	{
		int balance = user_balance.at(username);
		return balance;
	}
	catch(exception& e)
	{
		return 0;
	}
}


bool System:: get_login_status(string username)
{
	try
	{
		bool status = login_status.at(username);
		return status;
	}
	catch(exception& e)
	{
		return false;
	}
}

bool System::deposit_money(string username, int amt)
{
	try
	{
		user_balance[username] = amt + get_current_balance(username);
		return true;
	}
	catch(exception& e)
	{
		return false;
	}
}