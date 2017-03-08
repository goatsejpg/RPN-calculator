#pragma once

#ifndef OPERANDS_H
#define OPERANDS_H

#include <cstdint>
#include <vector>

struct operatorArgPair {
	bool (*func)(std::vector<double>*);
	std::string argString;
	operatorArgPair(bool (*f)(std::vector<double>*), const std::string& t): func(f), argString(t) {}
	~operatorArgPair() = default;
};

extern operatorArgPair* operatorArgPairs[32];

void start();
void end();
void print();

bool checkEnoughArgs(std::vector<double>* stack, const uint8_t& quantity);
bool operate(std::vector<double>* stack, const char* operatorArg, const std::size_t pos);

bool ADD(std::vector<double>* stack);
bool SUB(std::vector<double>* stack);
bool MUL(std::vector<double>* stack);
bool DIV(std::vector<double>* stack);
bool POW(std::vector<double>* stack);
bool SQRT(std::vector<double>* stack);
bool LOG(std::vector<double>* stack);
bool L10(std::vector<double>* stack);
bool L2(std::vector<double>* stack);
bool MOD(std::vector<double>* stack);

bool SIN(std::vector<double>* stack);
bool COS(std::vector<double>* stack);
bool TAN(std::vector<double>* stack);
bool ASIN(std::vector<double>* stack);
bool ACOS(std::vector<double>* stack);
bool ATAN(std::vector<double>* stack);	
bool SINH(std::vector<double>* stack);
bool COSH(std::vector<double>* stack);
bool TANH(std::vector<double>* stack);

bool CEIL(std::vector<double>* stack);
bool FLR(std::vector<double>* stack);
bool RND(std::vector<double>* stack);

bool ABS(std::vector<double>* stack);
bool NEG(std::vector<double>* stack);

bool PI(std::vector<double>* stack);
bool E(std::vector<double>* stack);
bool RANDOM(std::vector<double>* stack);
bool RANDOM_RANGE(std::vector<double>* stack);
bool RANDOM_INT(std::vector<double>* stack);
bool RANDOM_INT_RANGE(std::vector<double>* stack);

bool LCM(std::vector<double>* stack);
bool HCF(std::vector<double>* stack);

#endif // OPERANDS_H