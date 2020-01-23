/*

//Lecture1_5.cpp : Program in the lecture 1
//					Counting letter grades.
//					While loop and switch

#include <iostream>

using namespace std;

int main()
{
	int grade;       // variable for each grade
	int A_cnt = 0;  // number of As
	int B_cnt = 0;  // number of Bs
	int C_cnt = 0;  // number of Cs
	int D_cnt = 0;  // number of Ds
	int F_cnt = 0;  // number of Fs

	cout << "Enter the letter grades for each student." << endl << "Enter '#' character to end input." << endl;

	// loop until user types # key sequence
	while ((grade = cin.get()) != '#') {// determine which grade was input
		switch (grade) {  // switch structure nested in while
		case 'A':        // grade was uppercase A
		case 'a':        // or lowercase a
			++A_cnt;     // increment aCount
			break;        // necessary to exit switch

		case 'B':        // grade was uppercase B
		case 'b':        // or lowercase b
			++B_cnt;     // increment bCount
			break;        // exit switch

		case 'C':        // grade was uppercase C
		case 'c':        // or lowercase c
			++C_cnt;     // increment cCount
			break;        // exit switch

		case 'D':        // grade was uppercase D
		case 'd':        // or lowercase d
			++D_cnt;     // increment dCount
			break;        // exit switch

		case 'F':        // grade was uppercase F
		case 'f':        // or lowercase f
			++F_cnt;     // increment fCount
			break;        // exit switch

		case '\n':       // ignore newlines,
		case '\t':       // tabs,
		case ' ':        // and spaces in input
			break;        // exit switch

		default:         // catch all other characters
			cout << "Incorrect letter grade entered." << " Enter a new grade." << endl;
			break;        // optional; will exit switch anyway

		} // end switch
	} // end while

	// output summary of results
	cout << "\n\nTotals for each letter grade are:"
		<< "\nA: " << A_cnt   // display number of A grades
		<< "\nB: " << B_cnt   // display number of B grades
		<< "\nC: " << C_cnt   // display number of C grades
		<< "\nD: " << D_cnt   // display number of D grades
		<< "\nF: " << F_cnt   // display number of F grades
		<< endl;
	
	return 0;  // indicate successful termination

} // end function main

*/