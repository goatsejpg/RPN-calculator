#include <math.h>
#include <iostream>
#include <cstdint>
#include <string.h>
#include <random>
#include <cstdlib>
#include "operands.h"
#include "error.h"

operatorArgPair* pairs[32];

void start() {
	pairs[0] = new operatorArgPair(&ADD, "+");
	pairs[1] = new operatorArgPair(&SUB, "-");
	pairs[2] = new operatorArgPair(&MUL, "x");
	pairs[3] = new operatorArgPair(&DIV, "/");
	pairs[4] = new operatorArgPair(&POW, "pow");
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
	pairs[24] = new operatorArgPair(&PI, "pi");
	pairs[25] = new operatorArgPair(&E, "e");
	pairs[26] = new operatorArgPair(&HCF, "hcf");
	pairs[27] = new operatorArgPair(&LCM, "lcm");
	pairs[28] = new operatorArgPair(&RANDOM, "random");
	pairs[29] = new operatorArgPair(&RANDOM_INT, "randomint");
	pairs[30] = new operatorArgPair(&RANDOM_RANGE, "randomrange");
	pairs[31] = new operatorArgPair(&RANDOM_INT_RANGE, "randomintrange");
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
		printError("x takes 2 argument");
		return false;
	}
	return true;
}

bool DIV(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		if (stack->back() == 0) {
			printError("division by 0 exception.");
			return false;
		}
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
		printError("pow takes 2 argument");
		return false;
	}
	return true;
}

bool SQRT(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		if (stack->back() < 0) {
			printError("negative root exception.");
			return false;
		}
		stack->back() = sqrt(stack->back());
	} else {
		printError("root takes 1 argument");
		return false;
	}
	return true;
}

bool LOG(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		if (stack->back() < 0) {
			printError("negative logarithm exception.");
			return false;
		}
		stack->back() = log(stack->back());
	} else {
		printError("log takes 1 argument");
		return false;
	}
	return true;
}

bool L10(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		if (stack->back() < 0) {
			printError("negative logarithm exception.");
			return false;
		}
		stack->back() = log10(stack->back());
	} else {
		printError("log10 takes 1 argument");
		return false;
	}
	return true;
}

bool L2(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		if (stack->back() < 0) {
			printError("negative logarithm exception.");
			return false;
		}
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
		if (stack->back() < -1 || stack->back() > 1) {
			printError("asin of number greater than +-1 exception.");
			return false;
		}
		stack->back() = asin(stack->back());
	} else {
		printError("asin takes 1 argument");
		return false;
	}
	return true;
}

bool ACOS(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 1)) {
		if (stack->back() < -1 || stack->back() > 1) {
			printError("acos of number greater than +-1 exception.");
			return false;
		}
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

bool PI(std::vector<double>* stack) {
	stack->push_back(3.14159265359);
	return true;
}

bool E(std::vector<double>* stack) {
	stack->push_back(2.71828182845);
	return true;
}

bool RANDOM(std::vector<double>* stack) {
	stack->push_back(rand() / (double)RAND_MAX);
	return true;
}

bool RANDOM_RANGE(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end() -2) = *(stack->end() -2) + ((rand() / (double)RAND_MAX) * stack->back());
		stack->pop_back();
		return true;
	} else {
		printError("randomrange takes 2 argument");
		return false;	
	}
}

bool RANDOM_INT(std::vector<double>* stack) {
	stack->push_back(ceil(rand()));
	return true;
}

bool RANDOM_INT_RANGE(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		*(stack->end() -2) = ceil(*(stack->end() -2) + (rand() % (int)stack->back()));
		stack->pop_back();
		return true;
	} else {
		printError("randomintrange takes 2 argument");
		return false;	
	}
}

bool HCF(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		double prev = *(stack->end()-2);
		double mod = stack->back();
		double remain = fmod(prev, mod);
		while (remain != 0) {
			prev = mod;
			mod = remain;
			remain = fmod(prev, mod);
		}
		*(stack->end()-2) = mod;
		stack->pop_back();
	} else {
		printError("hcf takes 2 argument");
		return false;
	}
	return true;
}

bool LCM(std::vector<double>* stack) {
	if (checkEnoughArgs(stack, 2)) {
		double prev = *(stack->end()-2);
		double mod = stack->back();
		double remain = fmod(prev, mod);
		while (remain != 0) {
			prev = mod;
			mod = remain;
			remain = fmod(prev, mod);
		}
		*(stack->end()-2) = abs((*(stack->end()-2) * stack->back()) / mod);
		stack->pop_back();
	} else {
		printError("lcm takes 2 argument");
		return false;
	}
	return true;
}

bool operate(std::vector<double>* stack, const char* operatorArg, const std::size_t pos) {
	operatorArgPair* lulz = nullptr;
	for (auto i = std::begin(pairs); i != std::end(pairs); ++i) {
		if (!strcmp((*i)->argString.c_str(), operatorArg)) {
			lulz = *i;
		}
	}
	if (lulz == nullptr) {
		std::cerr << "ERROR: operator " << operatorArg << " not recognised at " << pos << std::endl; 
		return false;
	} else {
		return (*(lulz->func))(stack);
	}
	return true;
}
