#include "motor_vehicle.h"

MotorVehicle::MotorVehicle(int vin_, std::string make_, std::string model_, int price_) : Vehicle(make_, price_) {
	vin = vin_;
	model = model_;
}

MotorVehicle::MotorVehicle() {
	vin = -1;
	model = "";
}

std::string MotorVehicle::getInfo() {
	return Vehicle::getInfo() + model + ". #" + std::to_string(vin) + ". ";
}