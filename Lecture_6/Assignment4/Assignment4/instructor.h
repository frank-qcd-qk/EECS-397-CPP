#pragma once

#include <string>
#include <vector>

class Instructor {
public:
	int instructorID;
	std::string name;
	std::string department;
	int teachingCap;
	int currentLoad=0;

	Instructor(int instructorID_in, std::string name_in, std::string department_in);
	Instructor(int instructorID_in, std::string name_in, std::string department_in, int teachingCap_in);

	bool checkLoad(void);
	void addLoad(void);
private:


};