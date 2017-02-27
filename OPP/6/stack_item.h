#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <memory>

template <class T>
class StackItem
{
public:
	StackItem(const std::shared_ptr<T>& item);

	void setPrev(std::shared_ptr<StackItem<T>> prev);
	std::shared_ptr<StackItem<T>> getPrev();
	std::shared_ptr<T> getItem() const;

private:
	std::shared_ptr<T> m_item;
	std::shared_ptr<StackItem<T>> m_prev;

};

#include "list_item_impl.cpp"

#endif
