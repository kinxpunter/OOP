template <class T>
StackItem<T>::StackItem(const std::shared_ptr<T>& item)
{
	m_item = item;
}

template <class T>
void StackItem<T>::setPrev(std::shared_ptr<StackItem<T>> prev)
{
	m_prev = prev;
}



template <class T>
std::shared_ptr<StackItem<T>> StackItem<T>::getPrev()
{
	return m_prev;
}


template <class T>
std::shared_ptr<T> ListItem<T>::getItem() const
{
	return m_item;
}
