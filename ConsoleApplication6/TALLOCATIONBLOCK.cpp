#include "TAllocationBlock.h"
#include <iostream>

using namespace std;

// онструктор аллокатора пам€ти, заполнение блоков пам€ти
TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {
	_used_blocks = (char*)malloc(_size*_count);
	_free_blocks = (void**)malloc(sizeof(void*)*_count);

	for (size_t i = 0; i<_count; i++) _free_blocks[i] = _used_blocks + i*_size;
	_free_count = _count;
	std::cout << "TAllocationBlock: Memory init" <<endl;
}

//¬ыделение пам€ти, уменьшение количества свободных блоков пам€ти
void *TAllocationBlock::allocate() {
	void *result = nullptr;

	if (_free_count>0)
	{
		result = _free_blocks[_free_count - 1];
		_free_count--;
		cout << "TAllocationBlock: Allocate " << (_count - _free_count) <<
			" of " << _count << endl;
	}
	else
	{
		cout << "TAllocationBlock: No memory exception :-)" << endl;
	}

	return result;
}

//ќсвобождение пам€ти, увеличение количества блоков пам€ти
void TAllocationBlock::deallocate(void *pointer) {
	cout << "TAllocationBlock: Deallocate block " << endl;

	_free_blocks[_free_count] = pointer;
	_free_count++;
}
bool TAllocationBlock::has_free_blocks() {
	return _free_count>0;
}

/*ƒеструктор аллокатора.
≈сли количество свободных блоков пам€ти меньше количества всех элементов,
то не все блоки пам€ти были освобождены или освобождены неполностью*/
TAllocationBlock::~TAllocationBlock() {

	if (_free_count<_count) cout << "TAllocationBlock: Memory leak?" <<
		endl;
	else cout << "TAllocationBlock: Memory freed" <<
		endl;
	delete _free_blocks;
	delete _used_blocks;
}