#include "truck.h"

Truck::Truck(double milage_, int vin_, std::string make_, std::string model_, int price_, bool ref_, int hazmat_, int capacity_) : Cargo(ref_, hazmat_, capacity_) {
	milage = milage_;
	vin = vin_;
	model = model_;
}

std::string Truck::getInfo() {
	return MotorVehicle::getInfo() + ", " + std::to_string(milage) + " mpg, " + Cargo::getInfo();
}