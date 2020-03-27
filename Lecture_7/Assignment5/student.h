#pragma once
#include "person.h"
class Student :
	public Person
{
private:
	std::string major;
	int graduationYear;
	double gpa;
public:
	Student();
	Student(int input_ID_, std::string input_Name, int input_gradYear, std::string input_major, double input_GPA);
	std::string get_major();
	int get_graduationYear();
	double get_gpa();
	void set_major(std::string input_major);
	void set_graduationYear(int input_graduationYear);
	void set_gpa(double input_gpa);
};

