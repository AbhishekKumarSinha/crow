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
private:
	System();
	System(const System& rhs) = delete;
	static System* instance;

	unordered_map<string,string> accounts;
};

#endif