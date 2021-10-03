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