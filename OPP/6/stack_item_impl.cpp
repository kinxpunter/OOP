

template <class T>
StackItem<T>::StackItem(const std::shared_ptr<T>& item)
{
	m_item = item;
}

template <class T>
void StackItem<T>::setNext(std::shared_ptr<StackItem<T>> prev)
{
	m_prev = prev;
}



template <class T>
std::shared_ptr<StackItem<T>> StackItem<T>::getNext()
{
	return m_prev;
}


template <class T>
std::shared_ptr<T> StackItem<T>::getItem() const
{
	return m_item;
}
