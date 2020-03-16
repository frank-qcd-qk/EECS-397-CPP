#pragma once
#include <string>

class Vehicle {
public:
	std::string make;
	int price;

	Vehicle(std::string make_, int price_);

	Vehicle();

	std::string getInfo();
};