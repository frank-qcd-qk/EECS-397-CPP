#pragma once
#include <string>
#include<vector>
class Person
{
private:
	int userID;
	std::string userName;

public:
	Person(int input_ID_, std::string input_Name_);
	Person();
	int get_userID();
	void set_userID(int input_userID);
	std::string get_userName();
	void set_userName(std::string input_userName);
};

