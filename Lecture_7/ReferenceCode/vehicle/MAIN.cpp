#include <iostream>

#include "car.h"
#include "train_car.h"
#include "truck.h"
#include "motorcycle.h"

int main(const int argc, const char** argv) {

	TrainCar train_car = TrainCar("General Electric", 109000, "Cleveland-Pittsburgh", false, 2, 5000);

	Car automobile = Car(rand() % 10000, "Nissan", "Cube", 1, 4);

	Truck truck = Truck(75.0, rand() % 10000, "Kenworth", "Stratoliner", 50000, true, 0, 4000);

	Motorcycle bike = Motorcycle("Orange", 9001);

	std::cout << train_car.getInfo() << "\n";

	std::cout << automobile.getInfo() << "\n";
	std::cout << ((MotorVehicle)automobile).getInfo() << "\n";
	//std::cout << ((Passenger)automobile).getInfo() << "\n";//This doesn't work because MotorVehicle is private in Truck.

	std::cout << truck.getInfo() << "\n";

	std::cout << bike.getInfo() << "\n";//Uses MotorVehicle's version because it doesn't have its own.

	return 0;
}