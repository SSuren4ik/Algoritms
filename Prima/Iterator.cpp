//#include "Iterator.h"
//#include <iostream>
//using namespace std;
//
//Iterator::Iterator(Link* _h)
//{
//	h = _h;
//	cur = h->next;
//}
//bool Iterator::IsEmpty()
//{
//	return cur == nullptr;
//}
//bool Iterator::hasNext()
//{
//	return cur->next;
//}
//bool Iterator::hasCur()
//{
//	return cur;
//}
//Link* Iterator::GetNext()
//{
//	if (!hasNext())
//	{
//		throw exception();
//	}
//	cur = cur->next;
//	return cur;
//}
//Link* Iterator::GetCur()
//{
//	if (h == nullptr)
//	{
//		throw exception();
//	}
//	return cur;
//}
//Link* Iterator::GetHead()
//{
//	if (h == nullptr)
//	{
//		throw exception();
//	}
//	return h;
//}
