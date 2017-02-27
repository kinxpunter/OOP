#include "tree_item.h"

TreeItem::TreeItem(const std::shared_ptr <Figure>& figure)
{
	m_next = nullptr;
	m_figure = figure;
}

void TreeItem::setNext(std::shared_ptr <TreeItem> next)
{
	m_next = next;
}

std::shared_ptr<TreeItem> TreeItem::getNext()
{
	return m_next;
}

std::shared_ptr<Figure> TreeItem::getFigure() const
{
	return m_figure;
}
