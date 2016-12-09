#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H
#include <cstdlib>
class TAllocationBlock {
public:
	TAllocationBlock(size_t size, size_t count); //конструктор аллокатора памяти, заполнение блоков памяти
	void *allocate(); //выделение памяти, уменьшение количества свободных блоков памяти
	void deallocate(void *pointer); //освобождение памяти, увеличение количества блоков памяти
	bool has_free_blocks(); //количество свободных блоков памяти

	virtual ~TAllocationBlock();//деструктор аллокатора
private:
	size_t _size;
	size_t _count;

	char *_used_blocks;
	void **_free_blocks;

	size_t _free_count;

};
#endif /* TALLOCATIONBLOCK_H */