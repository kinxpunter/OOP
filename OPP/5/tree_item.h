
#include <memory>

template <class T>
class TreeItem
{
public:
	TreeItem(const std::shared_ptr <T>& item);
	void setNext(std::shared_ptr <TreeItem<T>> next);
	std::shared_ptr <TreeItem<T>> getNext();
	std::shared_ptr <T> getItem() const;
private:
	std::shared_ptr <T> m_item;
	std::shared_ptr <TreeItem> m_next;
};



#include "tree_item_impl.cpp"