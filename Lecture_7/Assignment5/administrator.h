#pragma once
#include "faculty.h"
#include "staff.h"
#include "student.h"
#include "researchAssistant.h"

#include <iostream>
class Administrator :
	public Faculty, public Staff
{
private:
	std::vector<Student> studentRoster;
	std::vector<ResearchAssistant> raRoster;
	std::vector<Faculty> facultyRoster;
	std::vector<Staff> staffRoster;
public:
	Administrator(std::string department, int salary, int id, std::string name);
	void addStudent(Student &toAdd);
	void addResearcher(ResearchAssistant &toAdd);
	void addFaculty(Faculty &toAdd);
	void addStaff(Staff &toAdd);
	std::string print();
	void remove(Student& student);
};

