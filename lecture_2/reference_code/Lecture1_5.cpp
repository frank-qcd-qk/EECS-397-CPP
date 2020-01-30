

//Lecture1_5.cpp : Program in the lecture 1
//                 Class average program with counter-controlled repetition.

#include <iostream>

using namespace std;

int main()
{
	// initialization phase
	double total = 0;        // sum of grades input by user
	int gradeCnt = 1;  // number of grade to be entered next
	int grade;        // grade value for each student
	double average;      // average of grades
				
	// processing phase
	while (gradeCnt <= 5) {          // loop 10 times
		cout << "Enter grade for student " << gradeCnt <<":  ";     // prompt for input
		cin >> grade;                // read grade from user
		total = total + grade;       // add grade to total
		//gradeCnt = gradeCnt + 1;  // increment counter
		//gradeCnt++;
		 gradeCnt +=1;
	}
	
	// termination phase
	average = total / (gradeCnt-1);   // integer division
	
	// display result
	cout << "Class average is= " << average << endl;
	return 0;   // indicate program ended successfully

} // end function main
