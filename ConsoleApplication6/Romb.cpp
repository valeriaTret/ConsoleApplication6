#include "Romb.h"
#include <iostream>
#include <cmath>

Romb::Romb(std::istream &is) {
	std::cout << "Create Romb" << std::endl;
	std::cout << "Insert side D1: ";
	is >> side_a;
	std::cout << "Insert side D2: ";
	is >> side_b;
}
void Romb::Print() {
	std::cout << "It's Romb" << std::endl
		<< "a = " << side_a << std::endl
		<< "b = " << side_b << std::endl;
}


Romb::~Romb()
{
	std::cout << "Romb deleted" << std::endl;
}
