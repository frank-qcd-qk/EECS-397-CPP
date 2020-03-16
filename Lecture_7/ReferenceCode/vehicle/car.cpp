#include "car.h"

Car::Car(int vin_, std::string make_, std::string model_, int price_, int seats_) : MotorVehicle(vin_, make_, model_, price_){
	seats = seats_;
}

std::string Car::getInfo() {
	return MotorVehicle::getInfo() + Passenger::getInfo();
}