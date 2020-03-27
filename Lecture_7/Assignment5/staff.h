#pragma once
#include "employee.h"
class Staff :
	public Employee
{
private:
	std::string title;
public:
	Staff();
	Staff(int input_ID, std::string input_name, int input_salary, std::string input_department, std::string input_title);
	void set_title(std::string input_title);
	std::string get_title();
};

