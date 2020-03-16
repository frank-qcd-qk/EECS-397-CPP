#include "cargo.h"

#include <string>

Cargo::Cargo(bool refrigerated_, int hazmat_, int capacity_) {
	refrigerated = refrigerated_;
	hazmat_class = hazmat_;
	capacity = capacity_;
}

Cargo::Cargo() {
	capacity = -1;
	hazmat_class = -1;
	refrigerated = false;
}

std::string Cargo::getInfo() {
	std::string info = "Hazmat class " + std::to_string(hazmat_class) + ". ";
	if (!refrigerated) {
		info += "Not ";
	}
	info += "Refrigerated. Capacity: " + std::to_string(capacity) + "lbs. ";
	return info;
}