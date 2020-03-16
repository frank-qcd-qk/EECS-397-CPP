#pragma once

#include "vehicle.h"
#include "cargo.h"

class TrainCar : Cargo, Vehicle{
public:
	std::string line;

	TrainCar(std::string make_, int price_, std::string line_, bool ref_, int hazmat_, int capacity_);

	std::string getInfo();
};