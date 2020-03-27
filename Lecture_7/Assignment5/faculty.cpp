#include "faculty.h"

Faculty::Faculty():Employee()
{
	position = "";
	researchFocus = "";
}

Faculty::Faculty(int input_ID, std::string input_name, int input_salary, std::string input_department, std::string input_position, std::string input_researchFocus): Employee(input_ID, input_name, input_salary, input_department)
{
	position = input_position;
	researchFocus = input_researchFocus;
}

void Faculty::set_position(std::string input_position)
{
	position = input_position;
}

void Faculty::set_researchFocus(std::string input_researchFocus)
{
	researchFocus = input_researchFocus;
}

std::string Faculty::get_position()
{
	return std::string(position);
}

std::string Faculty::get_researchFocus()
{
	return std::string(researchFocus);
}

bool Faculty::works_with(Faculty other)
{
	if ((other.get_researchFocus() == researchFocus) && (other.get_department() == this->get_department())) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Faculty::works_with(Staff other)
{
	if (other.get_department() == "") {
		return true;
	}
	if (other.get_department() == this->get_department()) {
		return true;
	}
	return false;
}

