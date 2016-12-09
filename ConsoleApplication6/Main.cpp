#include <cstdlib>
#include <iostream>
#include <memory>
#include "Trapeze.h"
#include "Romb.h"
#include "Pentagon.h"
#include "Figure.h"
#include "StackItem.h"
#include "Stack.h"
#include "TAllocationBlock.h"
void TestStack()
{
	TStack<Figure> stack;

	stack.push(std::shared_ptr<Figure>(new Trapeze(std::cin)));
	stack.push(std::shared_ptr<Figure>(new Romb(std::cin)));
	stack.push(std::shared_ptr<Figure>(new Pentagon(std::cin)));
	//stack.push(std::shared_ptr<Figure>(new Triangle(3, 3, 3)));

	for (auto i : stack) i->Print();



	while (!stack.empty()); std::cout << stack.pop() << std::endl;
}
void TestAllocationBlock()
{
	TAllocationBlock allocator(sizeof(int), 10);

	int *a1 = nullptr;
	int *a2 = nullptr;
	int *a3 = nullptr;
	int *a4 = nullptr;
	int *a5 = nullptr;

	a1 = (int*)allocator.allocate(); *a1 = 1; std::cout << "a1 pointer value:"
		<< *a1 << std::endl;
	a2 = (int*)allocator.allocate(); *a2 = 2; std::cout << "a2 pointer value:"
		<< *a2 << std::endl;
	a3 = (int*)allocator.allocate(); *a3 = 3; std::cout << "a3 pointer value:"
		<< *a3 << std::endl;

	allocator.deallocate(a1);
	allocator.deallocate(a3);
	a4 = (int*)allocator.allocate(); *a4 = 4; std::cout << "a4 pointer value:"
		<< *a4 << std::endl;
	a5 = (int*)allocator.allocate(); *a5 = 5; std::cout << "a5 pointer value:"
		<< *a5 << std::endl;
	std::cout << "a1 pointer value:" << *a1 << std::endl;
	std::cout << "a2 pointer value:" << *a2 << std::endl;
	std::cout << "a3 pointer value:" << *a3 << std::endl;
	allocator.deallocate(a2);
	allocator.deallocate(a4);
	allocator.deallocate(a5);
}
// templates stack on shared pointer with iterator and allocator on array
int main(int argc, char** argv) {

	TestAllocationBlock();
	TestStack();

	return 0;
}