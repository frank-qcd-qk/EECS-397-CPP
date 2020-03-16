#pragma once

#include "motor_vehicle.h"
#include "passenger.h"

class Car : public MotorVehicle, private Passenger {
public:
	Car(int vin_, std::string make_, std::string model_, int price_, int seats_);

	std::string getInfo();
};