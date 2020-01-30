

//Lecture1_6.cpp : Program in the lecture 1
//					Using the do/while repetition structure.
#include <iostream>

using namespace std;

int main()
{
	int counter = 1;              // initialize counter
	
	do {
		cout << counter << " \t ";   // display counter

	} while (++counter <= 5);  // end do/while
	
	cout << endl;
	return 0;   // indicate successful termination

} // end function main

