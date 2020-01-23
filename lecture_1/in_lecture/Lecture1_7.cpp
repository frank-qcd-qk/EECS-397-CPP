/*

//Lecture1_6.cpp : Program in the lecture 1
//					Using the break statement in a for structure.
					
#include <iostream>

using std::cout;
using std::endl;

// function main begins program execution
int main()
{
	int x;  // x declared here so it can be used after the loop
	// loop 10 times
	for (x = 1; x <= 10; x++) {
		// if x is 5, terminate loop
		if (x == 5)
			break;           // break loop only if x is 5

		cout << x << " ";   // display value of x

	} // end for 

	cout << "\nBroke out of loop when x became " << x << endl;
}

*/