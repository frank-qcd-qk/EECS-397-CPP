// Lecture7_inClass.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using std::cout;
using std::endl;

using std::fixed;
#include <iomanip>
using std::setprecision; 

#include "point.h"
#include "circle.h"
#include "cylinder.h"  // Cylinder class definition

int main()
{
	// --- Cylinder class demonstrations ----
	// instantiate Cylinder object
	Cylinder cylinder(12, 23, 2.5, 5.7);

	// display point coordinates
	cout << "X coordinate is " << cylinder.getX()
		<< "\nY coordinate is " << cylinder.getY()
		<< "\nRadius is " << cylinder.getRadius()
		<< "\nHeight is " << cylinder.getHeight();

	cylinder.setX(2);          // set new x-coordinate
	cylinder.setY(2);          // set new y-coordinate
	cylinder.setRadius(4.25);  // set new radius
	cylinder.setHeight(10);    // set new height

	// display new cylinder value
	cout << "\n\nThe new location and radius of circle are\n";
	cylinder.print();

	// display floating-point values with 2 digits of precision
	cout << fixed << setprecision(2);

	// display cylinder's diameter
	cout << "\n\nDiameter is " << cylinder.getDiameter();
	// display cylinder's circumference
	cout << "\nCircumference is "<< cylinder.getCircumference();
	// display cylinder's area
	cout << "\nArea is " << cylinder.getArea();
	// display cylinder's volume
	cout << "\nVolume is " << cylinder.getVolume();
	cout << endl;
		
}

