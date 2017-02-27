#ifndef STACK_H
#define STACK_H

#include <iostream>


	template<class T>
	class Stack
	{
	public:
	    Stack();
		~Stack();

		void push(const std::shared_ptr<T>& item);
		void pop();
		unsigned int size() const;
		bool empty() const;

    Iterator<StackItem<T>, T> begin() const;
	Iterator<StackItem<T>, T> end() const;

	template <class K>
	friend std::ostream& operator << (std::ostream& os, const Stack<K>& stack);

	private:
		std::shared_ptr<StackItem<T>> top;
		std::shared_ptr<StackItem<T>> prev;
		unsigned int m_size;
	};
#include "stack_impl.cpp"
#endif
