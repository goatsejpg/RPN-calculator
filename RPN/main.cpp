#include <iostream>
#include <vector>
#include <string.h>

#include "operands.h"
#include "error.h"

bool isNum(const char* str, double* ret) {
	char* endptr = 0;
	*ret = strtod(str, &endptr);

	if (*endptr != '\0' || endptr == str)
		return false;
	return true;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "ERROR: No arguments passed! -h for help" << std::endl;
		return -1;
	} else {
		start();
		std::vector<double> stack;
		stack.reserve(argc - 1);
		if (!strcmp(argv[1], "-h")) {
			std::cout << "Reverse Polish Notation Calculator (RPN)\n"
			"Put operators after the terms, for example adding 2 and 5 together is\n"
			"> 2 5 +\n"
			"and 4 x ( 1 - 3 ) + 3 is\n"
			"> 4 1 3 - x 3 +\n"
			"The quadratic formula is\n"
			"> b negate b 2 ^ 4 a c x x - root PLUSMINUS 2 a x /\n"
			"where PLUSMINUS can be + or -\n"
			"COMMANDS -\n"
			"-l : lists all operators" << std::endl;
			return 0;
		} else {
			if (!strcmp(argv[1], "-l")) {
				print();
				return 0;
			}
		}
		double ret;
		for (std::size_t pos = 1; pos < argc; ++pos) {
			if (isNum(argv[pos], &ret)) {
				stack.push_back(ret);
			} else {
				if (!operate(&stack, argv[pos], pos)) return 1;
			}
		}
		if (stack.size() > 1) {
			std::cerr << "ERROR: " << stack.size() - 1 << " extra numbers left in the stack, perhaps too few operators or too many numbers defined?\nSTACK:" << std::endl;
			short c = 0;
			for (auto i = stack.begin(); i != stack.end(); ++i) {
				std::cout << '[' << c << ']' << *i << " ";
				std::cout << std::flush;
				c++;
			}
		} else {
			std::cout << stack.front() << std::endl;
		}
		end();
	}
	return 0;
}
