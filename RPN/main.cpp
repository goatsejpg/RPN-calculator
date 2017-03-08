#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <random>
#include <time.h>

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
	srand(time(NULL));
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
			"> b negate b 2 pow 4 a c x x - root PLUSMINUS 2 a x /\n"
			"where PLUSMINUS can be + or -\n"
			"COMMANDS -\n"
			"-l  : lists all operators.\n"
			"-lh : extensive operator list and explanation." << std::endl;
			return 0;
		} else {
			if (!strcmp(argv[1], "-l")) {
				print();
				return 0;
			} else {
				if (!strcmp(argv[1], "-lh")) {

				std::cout <<
				"OPERATOR LIST:\n"
				"STANDARD OPERATORS -\n"
				"(+) two inputs - sums two numbers.\n"
				"(-) two inputs - subtracts two number.\n"
				"(x) two inputs - multiplies two numbers.\n"
				"(/) two inputs - divides two numbers.\n"
				"(pow) two input - raises first input to magnitude of input two.\n"
				"(root) one input - returns square root of its input.\n"
				"(log) one input - returns natural logarithm of its input.\n"
				"(log10) one input - returns log10 of its input.\n"
				"(log2) one input - returns log2 of its input.\n"
				"(%) two inputs - returns modulo of its two inputs (remainder from division).\n\n"
				"TRIGONOMETRY FUNCTIONS -\n"
				"(sin, cos, tan) one input - trigonometric functions of its input (radians).\n"
				"(asin, acos, atan) one input - arc trigonometric functions of its input (radians).\n"
				"(sinh, cosh, tanh) one input - hyperbole trigonometric functions of its input (radians).\n\n"
				"CONSTANTS -\n"
				"(pi) no input - returns the pi constant.\n"
				"(e) no input - returns the Euler's number constant (e).\n\n"
				"FUNCTIONS -\n"
				"(ceil) one input - returns the ceiling of the input (rounds up).\n"
				"(floor) one input - returns the floor of the input (rounds down).\n"
				"(round) one input - returns the input rounded to the nearest integer.\n"
				"(abs) one input - returns the absolute value of its input.\n"
				"(negate) one input - negates the input.\n"
				"(hcf) two input - returns the highest common factor of its two inputs.\n"
				"(lcm) two input - retusnt the lowest common multiple of its two inputs.\n"
				"(random, randomint) no input - returns a random real number or integer respectively.\n"
				"(randomrange, randomintrange) two inputs - returns a random real number or integer respectively\n"
				"                              within the range starting at the first input with a range of the second input.\n"
				<< std::endl;
					return 0;

				}
			}
		}
		std::cout << std::fixed << std::setprecision(6);
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
