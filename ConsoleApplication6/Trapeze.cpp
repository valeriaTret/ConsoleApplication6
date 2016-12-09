#include "Trapeze.h"
#include <iostream>
//#include <cmath>


Trapeze::Trapeze(std::istream &is) {
	std::cout << "Create Trapeze" << std::endl;
	std::cout << "Insert side A: ";
	is >> side_a;
	std::cout << "Insert side B: ";
	is >> side_b;
	std::cout << "Insert side C: ";
	is >> side_c;
	std::cout << "Insert side D: ";
	is >> side_d;
}


void Trapeze::Print() {
	std::cout << "It's Trapeze" << std::endl
		<< "a = " << side_a << std::endl
		<< "b = " << side_b << std::endl
		<< "c = " << side_c << std::endl
		<< "d = " << side_d << std::endl;
}


Trapeze::~Trapeze()
{
	std::cout << "Trapeze deleted" << std::endl;
}
