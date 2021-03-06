#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class System
{
public:
	static System* get_instance();
	bool signup(string username, string password);
	bool check_username_availability(string username);
	bool check_login_credentials(string username, string password);
	void set_login_status(string username, bool status);
	bool get_login_status(string username);
	int get_current_balance(string username);
	bool deposit_money(string username, int amt);
private:
	System();
	System(const System& rhs) = delete;
	static System* instance;

	unordered_map<string,string> accounts;
	unordered_map<string,bool> login_status;
	unordered_map<string,int> user_balance;
};

#endif