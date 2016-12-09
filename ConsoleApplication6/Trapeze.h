#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze(std::istream &is);
	void Print() override;

	virtual ~Trapeze();
private:
	size_t side_a;
	size_t side_b;
	size_t side_c;
	size_t side_d;
};
#endif // !TRAPEZE_H