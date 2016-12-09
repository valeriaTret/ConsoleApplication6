#include "Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon(std::istream &is) {
	std::cout << "Create Pentagon" << std::endl;
	std::cout << "Insert side A: ";
	is >> side_a;
	std::cout << "Insert side R: ";
	is >> side_b;
}
void Pentagon::Print() {
	std::cout << "It's Pentagon" << std::endl
		<< "a = " << side_a << std::endl
		<< "b = " << side_b << std::endl;
}

Pentagon::~Pentagon()
{
	std::cout << "Pentagon deleted" << std::endl;
}
