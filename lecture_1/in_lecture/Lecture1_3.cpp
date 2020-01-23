/*
//Lecture1_3.cpp : Program in the lecture 1
//				 If statements, relational operations


#include <iostream> //include standard library

using std::cout;
using std::cin;
using std::endl;

//using namespace std;

int main()
{
	int num1;  // first number to be read from user
	int num2;  // second number to be read from user
	
	cout << "Enter two integers, and I will tell you\n"<< "the relationships they satisfy: ";
	cin >> num1 >> num2;   // read two integers
	
	if (num1 == num2)
		cout << num1 << " is equal to " << num2 << endl;
	
	if (num1 != num2)
		cout << num1 << " is not equal to " << num2 << endl;
	
	if (num1 < num2)
		cout << num1 << " is less than " << num2 << endl;
	
	if (num1 > num2)
		cout << num1 << " is greater than " << num2 << endl;
	
	if (num1 <= num2)
		cout << num1 << " is less than or equal to "<< num2 << endl;
	
	if (num1 >= num2)
		cout << num1 << " is greater than or equal to "<< num2 << endl;
	
	return 0;   // indicate that program ended successfully

} // end function main


*/