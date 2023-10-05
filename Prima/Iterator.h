#pragma once
#include "Link.h"

class Iterator
{
	Link* cur;
	Link* h;
public:
	Iterator(Link* _h);
	bool IsEmpty();
	bool hasNext();
	Link* GetNext();
	Link* GetHead();
};
