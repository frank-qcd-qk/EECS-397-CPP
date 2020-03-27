#pragma once
#include "employee.h"
#include "staff.h"
class Faculty :
	public Employee
{
private:
	std::string position;
	std::string researchFocus;
public:
	Faculty();
	Faculty(int input_ID, std::string input_name, int input_salary, std::string input_department, std::string input_position, std::string input_researchFocus);
	void set_position(std::string input_position);
	void set_researchFocus(std::string input_researchFocus);
	std::string get_position();
	std::string get_researchFocus();
	bool works_with(Faculty other);
	bool works_with(Staff other);
};

