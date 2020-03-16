#pragma once

#include "motor_vehicle.h"

class Motorcycle : public MotorVehicle {
public:
	std::string color;
	int horsepower;

	Motorcycle(std::string color_, int horsepower_);
};