#include "administrator.h"

Administrator::Administrator(std::string department, int salary, int id, std::string name):Staff(id,name,salary,department,"Department Administrator")
{
	
}

void Administrator::addStudent(Student& toAdd)
{
	studentRoster.push_back(toAdd);
}

void Administrator::addResearcher(ResearchAssistant& toAdd)
{
	raRoster.push_back(toAdd);
}

void Administrator::addFaculty(Faculty& toAdd)
{
	facultyRoster.push_back(toAdd);
}

void Administrator::addStaff(Staff& toAdd)
{
	staffRoster.push_back(toAdd);
}

std::string Administrator::print()
{
	std::string returner="";
	std::cout << "Students:\n";
	for (Student x : studentRoster) {
		std::cout << x.get_userID() << ":	" << x.get_userName() << ".	Class of " << x.get_graduationYear() << ".	Majoring in " << x.get_major() << ".	GPA = " << x.get_gpa() << "." << std::endl;
	}
	std::cout << "Staff:" << std::endl;
	for (Staff x : staffRoster) {
		std::cout << x.get_userID() << ":	" << x.get_userName() << ".	" << x.get_title()<< ".	Works in " << x.get_department() << " for $" << x.get_salary() << "." << std::endl;
	}
	std::cout << "Faculty:" << std::endl;
	for (Faculty x : facultyRoster) {
		std::cout << x.get_userID() << ":	" << x.get_userName() << ".	" << x.get_position() << ".	Works in " << x.get_department() << " for $" << x.get_salary() << ".   Studies "<<x.get_researchFocus() <<"."<< std::endl;
	}
	std::cout << "Research assistants:" << std::endl;

	for (ResearchAssistant x : raRoster) {
		if (x.get_type()) {
			std::cout << x.get_personInfo() << ".	Class of " << x.get_graduationYear() << ".   Majoring in " << x.get_major() << ".   GPA = " << x.get_gpa() << ".   Studying"<<x.get_researchArea() << std::endl;
		}
		else
		{
			std::cout << x.get_personInfo() << ".	" << x.get_title() << ".   Works in " << x.get_department() << " for $" << x.get_salary() << ".   Studying" << x.get_researchArea() << std::endl;
		}
	}
	
	return returner;
}

void Administrator::remove(Student& student)
{
	int index = 0;
	for (Student x : studentRoster) {
		if (x.get_userID() == student.get_userID()) {
			studentRoster.erase(studentRoster.begin() + index);
			std::cout << "Student: " << student.get_userName() << " Removed!" << std::endl;
		}
		index++;
	}
}
