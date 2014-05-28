#include "radix.h"
#include <iostream>

int main() {
	std::cout << convert(1000, 16) << std::endl; // prints "3E8"
	std::cout << revert("3E8", 16) << std::endl; // prints "1000"
	std::cout << transvert("3E8", 16, 18) << std::endl; // prints "31A"
}