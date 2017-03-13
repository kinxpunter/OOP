
template <class T>
TreeItem<T>::TreeItem(const std::shared_ptr<T>& item)
{
	m_item = item;
}
template <class T>
void TreeItem<T>::setNext(std::shared_ptr<TreeItem<T>> next)
{
	m_next = next;
}
template <class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::getNext()
{
	return m_next;
}
template <class T>
std::shared_ptr<T> TreeItem<T>::getItem() const
{
	return m_item;
}
