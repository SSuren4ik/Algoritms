#include "PrimaD-Heap.h"
using namespace std;

Graph* PrimaDHeap::execute(Graph& graph)
{
	a.clear();
	b.clear();
	vt.clear();
	if (dh != nullptr)
		delete dh;
	n = graph.get_node_count();
	dh = new DHeap();
	a.resize(n);
	b.resize(n);
	vt.resize(n);
	int mt = 0;
	Graph* graph1 = new Graph(graph.get_node_count());
	int q;
	for (int i = 0; i < n; ++i)
	{
		vt[i] = 0;
	}
	int u = 0;
	vt[u] = 1;
	Link* tmp = graph.get_List()[0]->gethead()->next;
	while (tmp != nullptr)
	{
		a[tmp->src] = tmp->weight;
		b[tmp->src] = u;
		dh->insert(Pair(tmp->src, tmp->weight));
		tmp = tmp->next;
	}
	while (mt < n - 1)
	{
		Pair p;
		do
		{
			p = dh->getMin();
			dh->removeMin();
		} while (vt[p.first] != 0);
		u = p.first;
		q = b[u];
		vt[u] = 1;
		++mt;
		graph1->add_edge(q, u, a[u]);
		tmp = graph.get_List()[u]->gethead()->next;
		while (tmp != nullptr)
		{
			if (vt[tmp->src] == 0 && a[tmp->src] > tmp->weight)
			{
				dh->insert(Pair(tmp->src, tmp->weight));
				a[tmp->src] = tmp->weight;
				b[tmp->src] = u;
			}
			tmp = tmp->next;
		}
	}
	delete tmp;
	return graph1;
}
PrimaDHeap::~PrimaDHeap()
{
	delete dh;
	a.clear();
	b.clear();
	vt.clear();
}