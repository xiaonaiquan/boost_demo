#pragma once
#include <stdlib.h>

class Allocator
{
public:
	virtual ~Allocator() {}
	virtual void * Allocate(size_t iSize, size_t * pRealSize = NULL) = 0;
	virtual void Deallocate(void * pData) = 0;
public:
	static Allocator * Instance();
};

class MallocAllocator : public Allocator
{
public:
	virtual void * Allocate(size_t iSize, size_t * pRealSize = NULL);
	virtual void Deallocate(void * pData);
public:
	static MallocAllocator * Instance();
};


class NewAllocator : public Allocator
{
public:
	virtual void * Allocate(size_t iSize, size_t * pRealSize = NULL);
	virtual void Deallocate(void * pData);
public:
	static NewAllocator * Instance();
};