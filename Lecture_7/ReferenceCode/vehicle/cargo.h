#pragma once

#include <string>

class Cargo {
public:
	bool refrigerated;
	int hazmat_class;
	int capacity;

	Cargo(bool refrigerated_, int hazmat_, int capacity_);

	Cargo();

	std::string getInfo();
};