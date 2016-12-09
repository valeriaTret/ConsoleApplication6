#ifndef ROMB_H
#define ROMB_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Romb : public Figure {
public:
	Romb(std::istream &is);
	void Print() override;

	virtual ~Romb();
private:
	size_t side_a;
	size_t side_b;
};
#endif // !ROMB_H
