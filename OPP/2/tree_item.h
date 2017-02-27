#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include "square.h"

class TreeItem
{
public:
	TreeItem(const Square& square);

	void setNext(TreeItem* next);
	TreeItem* getNext();
	Square getSquare() const ;
private:
	Square m_square;
	TreeItem* m_next;
};

#endif
