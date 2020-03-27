#include "researchAssistant.h"
ResearchAssistant::ResearchAssistant(std::string area, std::string title, std::string department, int salary, int id, std::string name): Staff(id,name,salary,department,title)
{
	researchArea = area;
	username_local = name;
	id_local = id;
	type = 0;
}

ResearchAssistant::ResearchAssistant(std::string area, std::string major, double gpa, int grad_year, int id, std::string name):Student(id,name,grad_year,major,gpa)
{
	researchArea = area;
	username_local = name;
	id_local = id;
	type = 1;
}

void ResearchAssistant::set_researchArea(std::string input_area)
{
	researchArea = input_area;

}

std::string ResearchAssistant::get_researchArea()
{
	return std::string(researchArea);
}

int ResearchAssistant::get_type()
{
	return type;
}

std::string ResearchAssistant::get_personInfo()
{
	std::string returner = (std::to_string)(id_local) + ":	" + username_local;;
	return std::string(returner);
}
/*
ResearchAssistant::ResearchAssistant(std::string area, Student& student_in, Administrator& administrator_to_notify)
{
	researchArea = area;
	username_local = student_in.get_userName();
	id_local = student_in.get_userID();
	type = 1;
	//administrator_to_notify.remove(student_in);
}
*/