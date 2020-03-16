#pragma once

#include "vehicle.h"

class MotorVehicle : Vehicle {
public:
	int vin;
	std::string model;

	MotorVehicle(int vin_, std::string make_, std::string model_, int price_);

	MotorVehicle();

	std::string getInfo();
};