#include <math.h>
#include <iostream>
#include <cstdint>
#include <string.h>
#include "operands.h"
#include "error.h"

operatorArgPair* pairs[24];

void start() {
	pairs[0] = new operatorArgPair(&ADD, "+");
	pairs[1] = new operatorArgPair(&SUB, "-");
	pairs[2] = new operatorArgPair(&MUL, "x");
	pairs[3] = new operatorArgPair(&DIV, "/");
	pairs[4] = new operatorArgPair(&POW, "^");
	pairs[5] = new operatorArgPair(&SQRT, "root");
	pairs[6] = new operatorArgPair(&LOG, "log");
	pairs[7] = new operatorArgPair(&L10, "log10");
	pairs[8] = new operatorArgPair(&L2, "log2");
	pairs[9] = new operatorArgPair(&MOD, "%");
	pairs[10] = new operatorArgPair(&SIN, "sin");
	pairs[11] = new operatorArgPair(&COS, "cos");
	pairs[12] = new operatorArgPair(&TAN, "tan");
	pairs[13] = new operatorArgPair(&ASIN, "asin");
	pairs[14] = new operatorArgPair(&ACOS, "acos");
	pairs[15] = new operatorArgPair(&ATAN, "atan");
	pairs[16] = new operatorArgPair(&SINH, "sinh");
	pairs[17] = new operatorArgPair(&COSH, "cosh");
	pairs[18] = new operatorArgPair(&TANH, "tanh");
	pairs[19] = new operatorArgPair(&CEIL, "ceil");
	pairs[20] = new operatorArgPair(&FLR, "floor");
	pairs[21] = new operatorArgPair(&RND, "round");
	pairs[22] = new operatorArgPair(&ABS, "abs");
	pairs[23] = new operatorArgPair(&NEG, "negate");
}

void end() {
	for (std::size_t i = 0; i != 24; ++i) {
		delete pairs[i];
	}
}

void print() {
	std::cout << "OPERATORS:" << std::endl;
	for (auto i = std::begin(pairs); i != std::end(pairs); ++i) {
		std::cout << (*i)->argString;
		if (i != std::end(pairs) - 1) {
			std::cout << ", ";
		} else {
			std::cout << std::endl;
		}
	}
	std::cout << std::flush;
}

bool checkEnoughArgs(std::vector<double>* stack, const uint8_t& quantity) {
	return stack->size() >= quantity;
}

// DEFINITION OF OPERANDS GOING TO LINE 305
// OPERATE FUNCTION BELOW THESE DEFINITIONS
bool ADD(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) += stack->back();
		stack->pop_back();
	} else {
		printError("+ takes 2 argument");
		return false;
	}
	return true;
}

bool SUB(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) -= stack->back();
		stack->pop_back();
	} else {
		printError("- takes 2 argument");
		return false;
	}
	return true;
}

bool MUL(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) *= stack->back();
		stack->pop_back();
	} else {
		printError("* takes 2 argument");
		return false;
	}
	return true;
}

bool DIV(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) /= stack->back();
		stack->pop_back();
	} else {
		printError("/ takes 2 argument");
		return false;
	}
	return true;
}

bool POW(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) = pow(*(stack->end()-2), stack->back());
		stack->pop_back();
	} else {
		printError("^ takes 2 argument");
		return false;
	}
	return true;
}

bool SQRT(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = sqrt(stack->back());
	} else {
		printError("root takes 1 argument");
		return false;
	}
	return true;
}

bool LOG(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = log(stack->back());
	} else {
		printError("log takes 1 argument");
		return false;
	}
	return true;
}

bool L10(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = log10(stack->back());
	} else {
		printError("log10 takes 1 argument");
		return false;
	}
	return true;
}

bool L2(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = log2(stack->back());
	} else {
		printError("log2 takes 1 argument");
		return false;
	}
	return true;
}

bool MOD(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end()-2) = fmod(*(stack->end()-2), stack->back());
		stack->pop_back();
	} else {
		printError("% takes 2 argument");
		return false;
	}
	return true;
}

bool SIN(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = sin(stack->back());
	} else {
		printError("sin takes 1 argument");
		return false;
	}
	return true;
}

bool COS(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = cos(stack->back());
	} else {
		printError("cos takes 1 argument");
		return false;
	}
	return true;
}

bool TAN(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = tan(stack->back());
	} else {
		printError("tan takes 1 argument");
		return false;
	}
	return true;
}

bool ASIN(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = asin(stack->back());
	} else {
		printError("asin takes 1 argument");
		return false;
	}
	return true;
}

bool ACOS(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = acos(stack->back());
	} else {
		printError("acos takes 1 argument");
		return false;
	}
	return true;
}

bool ATAN(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = atan(stack->back());
	} else {
		printError("atan takes 1 argument");
		return false;
	}
	return true;
}

bool SINH(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = sinh(stack->back());
	} else {
		printError("sinh takes 1 argument");
		return false;
	}
	return true;
}

bool COSH(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = cosh(stack->back());
	} else {
		printError("cosh takes 1 argument");
		return false;
	}
	return true;
}

bool TANH(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = tanh(stack->back());
	} else {
		printError("tanh takes 1 argument");
		return false;
	}
	return true;
}

bool CEIL(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = ceil(stack->back());
	} else {
		printError("ceil takes 1 argument");
		return false;
	}
	return true;
}

bool FLR(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = floor(stack->back());
	} else {
		printError("floor takes 1 argument");
		return false;
	}
	return true;
}

bool RND(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = round(stack->back());
	} else {
		printError("round takes 1 argument");
		return false;
	}
	return true;
}

bool ABS(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = abs(stack->back());
	} else {
		printError("abs takes 1 argument");
		return false;
	}
	return true;
}

bool NEG(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		stack->back() = 0.0 - (stack->back());
	} else {
		printError("negate takes 1 argument");
		return false;
	}
	return true;
}


bool operate(std::vector<double>* stack, const char* operatorArg) {
	operatorArgPair* lulz = nullptr;
	unsigned short count;
	for (auto i = std::begin(pairs); i != std::end(pairs); ++i) {
		if (!strcmp((*i)->argString.c_str(), operatorArg)) {
			lulz = *i;
		}
		++count;
	}
	if (lulz == nullptr) {
		std::cerr << "ERROR: operator " << operatorArg << " not recognised." << std::endl; 
		return false;
	} else {
		return (*(lulz->func))(stack);
	}
	return true;
}
