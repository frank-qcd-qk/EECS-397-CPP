#pragma once

#include <string>
#include <vector>

class Student {
public:
	int studentID;
	std::string name;
	std::string major;
	int graduationYear;
	double gpa;

	Student(int studentID_in, std::string name_in, int graduationYear_in, std::string major_in, double gpa_in);

private:


};