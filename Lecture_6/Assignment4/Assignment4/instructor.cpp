#include "instructor.h"

Instructor::Instructor(int instructorID_in, std::string name_in, std::string department_in) {
	instructorID = instructorID_in;
	name = name_in;
	department = department_in;
}

Instructor::Instructor(int instructorID_in, std::string name_in, std::string department_in, int teachingCap_in)
{
	instructorID = instructorID_in;
	name = name_in;
	department = department_in;
	teachingCap = teachingCap_in;
	currentLoad = 0;
}

bool Instructor::checkLoad(void)
{
	if ((currentLoad + 1) > teachingCap){
		return false;
	}
	else
	{
		return true;
	}
}

void Instructor::addLoad(void)
{
	currentLoad++;
}
