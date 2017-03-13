
template<class T>
Stack<T>::Stack()
{
	top = NULL;
	m_size = 0;
}



template<class T>
Stack<T>::~Stack()
{
	while(top!=NULL);
	{
	pop();}
}

template<class T>
void Stack<T>::push(const std::shared_ptr<T>& item)
{
	std::shared_ptr<StackItem<T>> itemPtr = std::make_shared<StackItem<T>>(item);
if (m_size == 0)
	{
		top = itemPtr;
		prev = top;
	}
	else
	{
		prev->setNext(itemPtr);
		prev = itemPtr;
	}

	++m_size;
}

template<class T>
void Stack<T>::pop()
{
	if (m_size == 1)
	{
		top = nullptr;
		prev = nullptr;
	}
	else
		prev = prev->getNext();

	--m_size;
}



template<class T>
unsigned int Stack<T>::size() const
{
	return m_size;
}

template<class T>
bool Stack<T>::empty() const
{
	return m_size == 0;
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::begin() const
{
	return Iterator<StackItem<T>, T>(top);
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::end() const
{
	return Iterator<StackItem<T>, T>(nullptr);
}







template <class T>
Iterator<StackItem<T>, T> Stack<T>::get(unsigned int index) const
{
 if (index >= size())
 return end();

 Iterator<StackItem<T>, T> it = begin();

 while (index > 0)
 {
 ++it;
 --index;
 }

 return it;
}

template <class K>
std::ostream& operator << (std::ostream& os, const Stack<K>& stack)
{
	if (stack.size() == 0)
	{
		os << "================" << std::endl;
		os << "List is empty" << std::endl;
	}
	else
		for (std::shared_ptr<K> item : stack)
			item->print();

	return os;
}
