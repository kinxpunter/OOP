#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>


class Square 
{
public:
	Square();
	Square(std::istream& is);
	void print() const ;
	double area()  const;

	Square& operator = (const Square& other);
	bool operator == (const Square& other) const;

	friend std::ostream& operator << (std::ostream& os, const Square& square);
	friend std::istream& operator >> (std::istream& is, Square& square);

private:
	double m_side;
};

#endif
