#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>
#include "stack.h"

#define R_CAST(__ptr, __type) reinterpret_cast<__type>(__ptr)

class Allocator
{
public:
	Allocator(unsigned int blockSize, unsigned int count);
	~Allocator();

	void* allocate();
	void deallocate(void* p);
	bool hasFreeBlocks() const;

private:
	void* m_memory;
	Stack<unsigned int> m_freeBlocks;
};

#endif
