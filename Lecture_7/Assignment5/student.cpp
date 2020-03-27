#include "student.h"
Student::Student():Person() {
	major = "";
	graduationYear = 0;
	gpa = 0.0;
}

Student::Student(int input_ID_, std::string input_Name, int input_gradYear, std::string input_major, double input_GPA):Person(input_ID_,input_Name) {
	major = input_major;
	graduationYear = input_gradYear;
	gpa = input_GPA;
}

std::string Student::get_major()
{
	return std::string(major);
}

int Student::get_graduationYear()
{
	return graduationYear;
}

double Student::get_gpa()
{
	return gpa;
}

void Student::set_major(std::string input_major)
{
	major = input_major;
}

void Student::set_graduationYear(int input_graduationYear)
{
	graduationYear = input_graduationYear;
}

void Student::set_gpa(double input_gpa)
{
	gpa = input_gpa;
}

