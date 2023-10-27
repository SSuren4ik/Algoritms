#pragma once
#include "Graph.h"
#include "D-Heap.h"

class PrimaDHeap
{
private:
	int n;
	DHeap* dh;
	vector<int> a;
	vector<int> b;
	vector<bool> vt;
public:
	Graph* execute(Graph& graph);
	~PrimaDHeap();
};
