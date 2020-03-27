#include "person.h"


Person::Person(int input_ID_, std::string input_Name_)
{
	userID = input_ID_;
	userName = input_Name_;
}

Person::Person()
{
	userID = 0;
	userName = "";
}

int Person::get_userID()
{
	return userID;
}

void Person::set_userID(int input_userID)
{
	userID = input_userID;
}

std::string Person::get_userName()
{
	return userName;
}

void Person::set_userName(std::string input_userName)
{
	userName = input_userName;
}
