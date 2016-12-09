#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>
#include <iostream>
template <class node, class T>
class TIterator
{
public:
	TIterator(std::shared_ptr<node> n) { //текущий элемент

		node_ptr = n;
	}

	std::shared_ptr<T> operator * () { //возвращает значение
		return node_ptr->GetValue();
	}

	std::shared_ptr<T> operator -> () { //возвращает фигуру
		return node_ptr->GetValue();
	}

	void operator ++ () { //переход к следующему элементу
		node_ptr = node_ptr->GetNext();
	}

	TIterator operator ++ (int) {
		TIterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator == (TIterator const& i) { //сравнение
		return node_ptr == i.node_ptr;
	}

	bool operator != (TIterator const& i) { //сравнение
		return !(*this == i);
	}

private:
	std::shared_ptr<node> node_ptr;
};
#endif /* TITERATOR_H */