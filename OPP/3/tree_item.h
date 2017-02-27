#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include <memory>
#include "figure.h"

class TreeItem
{
public:
	TreeItem(const std::shared_ptr <Figure>& figure);
	void setNext(std::shared_ptr <TreeItem> next);
	std::shared_ptr <TreeItem> getNext();
	std::shared_ptr <Figure> getFigure() const;
private:
	std::shared_ptr <Figure> m_figure;
	std::shared_ptr <TreeItem> m_next;
};

#endif
