#include "tree_item.h"

TreeItem::TreeItem(const Square& square)
{
	m_next = NULL;
	m_square = square;
}

void TreeItem::setNext(TreeItem* next)
{
	m_next = next;
}

TreeItem* TreeItem::getNext()
{
	return m_next;
}

Square TreeItem::getSquare() const
{
	return m_square;
}
