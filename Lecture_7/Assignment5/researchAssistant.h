#pragma once
#include "student.h"
#include "staff.h"

class ResearchAssistant:
	public Student, public Staff
{
private:
	std::string researchArea;
	int type; //0:staff, 1: Student
	std::string username_local;
	int id_local;

public:
	ResearchAssistant(std::string area, std::string title, std::string department, int salary, int id, std::string name);
	ResearchAssistant(std::string area, std::string major, double gpa, int grad_year, int id, std::string name);
	void set_researchArea(std::string input_area);
	std::string get_researchArea();
	int get_type();
	std::string get_personInfo();
	class Administrator;
	//ResearchAssistant(std::string area, Student& student_in, Administrator& administrator_to_notify);
};

