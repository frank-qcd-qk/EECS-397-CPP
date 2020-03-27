#pragma once
#include "person.h"
class Employee :
	public Person
{
private:
	int salary;
	std::string department;
public:
	Employee();
	Employee(int input_ID, std::string input_name, int input_salary, std::string input_department);
	int get_salary();
	std::string get_department();
	void set_salary(int input_salary);
	void set_department(std::string input_department);
	bool works_with(Employee other);
};

