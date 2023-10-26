#pragma once
#include "Graph.h"
#include "D-Heap.h"

using namespace std;

class PrimaDHeap
{
private:
	int n;
	DHeap* dh;
	int* a;
	int* b;
	bool* vt;
public:
	PrimaDHeap(const Graph& graph);
	Graph* execute(Graph& graph);
	~PrimaDHeap();
};
