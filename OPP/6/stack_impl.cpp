template<class T>
Stack<T>::Stack()
{
	top = NULL;
	m_size = 0;
}



template<class T>
Stack<T>::~Stack()
{
	clear();
}

template<class T>
void Stack<T>::push(const std::shared_ptr<T>& item)
{
	std::shared_ptr<QueueItem<T>> itemPtr = std::make_shared<QueueItem<T>>(item);
if (m_size == 0)
	{
		m_top = itemPtr;
		m_prev = m_top;
	}
	else
	{
		m_prev->setNext(itemPtr);
		m_prev = itemPtr;
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
Iterator<ListItem<T>, T> List<T>::begin() const
{
	return Iterator<ListItem<T>, T>(m_begin);
}

template <class T>
Iterator<ListItem<T>, T> List<T>::end() const
{
	return Iterator<ListItem<T>, T>(nullptr);
}

template <class K>
std::ostream& operator << (std::ostream& os, const Stack<K>& stack)
{
	if (list.size() == 0)
	{
		os << "================" << std::endl;
		os << "List is empty" << std::endl;
	}
	else
		for (std::shared_ptr<K> item : stack)
			item->print();

	return os;
}
