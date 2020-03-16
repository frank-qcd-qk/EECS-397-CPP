#pragma once

#include "vehicle.h"

class Passenger : Vehicle {
public:
	int seats;

	Passenger();

	std::string getInfo();
};