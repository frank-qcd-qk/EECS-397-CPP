#pragma once

#include "motor_vehicle.h"
#include "cargo.h"

class Truck : MotorVehicle, Cargo {
public:
	double milage;

	Truck(double milage_, int vin_, std::string make_, std::string model_, int price_, bool ref_, int hazmat_, int capacity_);

	std::string getInfo();
};