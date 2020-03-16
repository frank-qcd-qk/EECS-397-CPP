#include "motor_vehicle.h"
#include "passenger.h"

class Bus : MotorVehicle, Passenger{
public:
	Bus(int vin_, std::string make_, std::string model_, int price_) : MotorVehicle(vin_, make_, model_, price_) {
		seats = 50;
	}
};