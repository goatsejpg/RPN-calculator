#include <iostream>
#include "error.h"

void printError(const std::string& in) {
	std::cerr << "ERROR: " << in << std::endl;
};