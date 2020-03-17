#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

#include "student.h"
#include "instructor.h"

class Course {
public:
	std::string title;
	std::string department;
	int number;
	std::string building;
	int roomNumber;
	std::string instructorName;
	int capacity;
	int classLoad=0;

	Course(std::string title_in, std::string department_in, int number_in, std::string building_in, int roomNumber_in);
	Course(std::string title_in, std::string department_in, int number_in, std::string building_in, int roomNumber_in, int studentCap_in);
	std::vector<Student> addStudents(std::vector<Student> students_to_add);
	bool dropStudent(Student student_to_remove);
	bool addInstructor(Instructor& instructor_to_add);
	void printStudents(void);

private:
	bool checkStudentExist(Student student_to_check);
	std::vector<Student> enrolledStudent;
};