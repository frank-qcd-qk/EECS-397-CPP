#include "course.h"

Course::Course(std::string title_in, std::string department_in, int number_in, std::string building_in, int roomNumber_in)
{
	title = title_in;
	department = department_in;
	number = number_in;
	building = building_in;
	roomNumber = roomNumber_in;
	capacity = 2147483647;
}

Course::Course(std::string title_in, std::string department_in, int number_in, std::string building_in, int roomNumber_in, int studentCap_in)
{
	title = title_in;
	department = department_in;
	number = number_in;
	building = building_in;
	roomNumber = roomNumber_in;
	capacity = studentCap_in;
}

std::vector<Student> Course::addStudents(std::vector<Student> students_to_add)
{
	// Seperate how much can add:
	int toAdd = capacity - classLoad;
	//std::cout << "You can add: " << toAdd << std::endl;
	int counter = 0;
	std::vector<Student> kickedList;

	for (auto studentCandidate:students_to_add)
	{
		if (!checkStudentExist(studentCandidate)) {
			if ((counter) < toAdd) {
				enrolledStudent.push_back(studentCandidate);
				classLoad++;
				counter++;
			}
			else
			{
				kickedList.push_back(studentCandidate);
			}
		}
		else {
			//std::cout << "Student: " << studentCandidate.name << " already enrolled! Pass..." << std::endl;
		}
	}
	return kickedList;
}

bool Course::dropStudent(Student student_to_remove)
{
	int index = 0;
	for (auto studentInInterest : enrolledStudent) {
		if (student_to_remove.studentID == studentInInterest.studentID) {
			enrolledStudent.erase(enrolledStudent.begin() + index);
			classLoad--;
			//std::cout << "Removed student: " << student_to_remove.name << std::endl;
			return true;
		}
		index++;
	}
	return false;
}


bool Course::addInstructor(Instructor& instructor_to_add) {

	if (instructor_to_add.checkLoad()) {
		//std::cout << "Instructor: " << instructor_to_add.name << " Current load is: " << instructor_to_add.currentLoad << std::endl;
		instructor_to_add.addLoad();
		instructorName=instructor_to_add.name;
		return true;
	}
	else {
		return false;
	}

	
}

void Course::printStudents(void)
{
	std::cout << "==========Enrolled Roster for "<<title<<"==========" << std::endl;
	for (auto studentInList : enrolledStudent) {
		std::cout << studentInList.name << std::endl;
	}
	std::cout << "==========END==========" << std::endl;
}

bool Course::checkStudentExist(Student student_to_check)
{
	for (auto studentInList : enrolledStudent) {
		if (studentInList.studentID== student_to_check.studentID) {
			return true;
		}
	}
	return false;
}