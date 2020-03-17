#include "student.h"

Student::Student(int studentID_in, std::string name_in, int graduationYear_in, std::string major_in,  double gpa_in) {
	studentID = studentID_in;
	name = name_in;
	major = major_in;
	graduationYear = graduationYear_in;
	gpa = gpa_in;
}
