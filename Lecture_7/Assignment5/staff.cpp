#include "staff.h"

Staff::Staff()
{
	title = "";
}

Staff::Staff(int input_ID, std::string input_name, int input_salary, std::string input_department, std::string input_title): Employee(input_ID,input_name, input_salary, input_department)
{
	title = input_title;
}

void Staff::set_title(std::string input_title)
{
	title = input_title;
}

std::string Staff::get_title()
{
	return std::string(title);
}

