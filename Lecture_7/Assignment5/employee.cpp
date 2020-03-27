#include "employee.h"

Employee::Employee():Person()
{
	salary = 0;
	department = "";
}

Employee::Employee(int input_ID, std::string input_name, int input_salary, std::string input_department):Person(input_ID,input_name)
{
	salary = input_salary;
	department = input_department;
}

int Employee::get_salary()
{
	return salary;
}

std::string Employee::get_department()
{
	return std::string(department);
}

void Employee::set_salary(int input_salary)
{
	salary = input_salary;
}

void Employee::set_department(std::string input_department)
{
	department = input_department;
}

bool Employee::works_with(Employee other)
{
	if (other.get_department() == department) {
		return true;
	}
	else
	{
		return false;
	}
}
