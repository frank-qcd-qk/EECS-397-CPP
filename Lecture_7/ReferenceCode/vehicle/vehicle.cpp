#include "vehicle.h"

Vehicle::Vehicle(std::string make_, int price_) {
	make = make_;
	price = price_;
}

Vehicle::Vehicle() {
	make = "";
	price = 0;
}

std::string Vehicle::getInfo() {
	return "$" + std::to_string(price) + ": " + make;
}