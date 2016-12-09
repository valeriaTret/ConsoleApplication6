#ifndef TSTACK_H
#define TSTACK_H
#include "Iterator.h"
#include "StackItem.h"
#include <memory>
template <class T> class TStack {
public:
	TStack();

	void push(std::shared_ptr<T> &&item);
	bool empty();

	TIterator<TStackItem<T>, T> begin();
	TIterator<TStackItem<T>, T> end();

	std::shared_ptr<T> pop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const
		TStack<A>& stack);
	virtual ~TStack();
private:

	std::shared_ptr<TStackItem<T>> head;
};
#endif /* TSTACK_H */