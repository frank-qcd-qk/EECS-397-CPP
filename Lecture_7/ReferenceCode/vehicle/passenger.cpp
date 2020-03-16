#include "passenger.h"

Passenger::Passenger() {
	seats = 0;
}

std::string Passenger::getInfo() {
	return "Seats " + std::to_string(seats) + ". ";
}