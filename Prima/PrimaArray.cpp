#include "PrimaArray.h"

PrimaArray::PrimaArray(const Graph& graph)
{
	n = graph.get_node_count();
	a = new int[n];
	b = new int[n];
	vt = new bool[n];
}
Graph PrimaArray::execute(const Graph& graph)
{
	int mt = 0;
	for (int i = 0; i < n; ++i)
	{
		vt[i] = 0;
	}
	int u = 1;
	vt[u] = 1;
	//for()


	return Graph();
}