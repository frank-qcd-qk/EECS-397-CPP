#include "train_car.h"

TrainCar::TrainCar(std::string make_, int price_, std::string line_, bool ref_, int hazmat_, int capacity_) {
	make = make_;
	price = price_;
	line = line_;
	refrigerated = ref_;
	hazmat_class = hazmat_;
	capacity = capacity_;
}

std::string TrainCar::getInfo() {
	return
		"A $" + std::to_string(price) + " " + make + "-brand train car on the " + line +
		" line. It is " + (!refrigerated ? "not " : "") + "refrigerated, has a hazmat classification of " + std::to_string(hazmat_class) +
		", and a capacity of " + std::to_string(capacity) + ".";
}