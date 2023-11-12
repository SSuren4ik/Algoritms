#include "PrimaD-Heap.h"
using namespace std;

int PrimaDHeap::execute(Graph& graph)
{
	n = graph.get_node_count();
	dh = new DHeap();
	a.resize(n, INT_MAX);
	b.resize(n);
	vt.resize(n);
	int mt = 0;
	int sum=0;
	Graph graph1(n);
	int q;
	for (int i = 0; i < n; ++i)
	{
		vt[i] = 0;
	}
	int u = 0;
	int last_u = u;
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
		try
		{
			do
			{
				p = dh->getMin();
				dh->removeMin();
			} while (vt[p.first] != 0);
		}
		catch (exception exp)
		{
			return sum;
		}
		if (a[p.first] == INT_MAX)
		{
			return sum;
		}
		u = p.first;
		q = b[u];
		vt[u] = 1;
		++mt;
		graph1.add_edge(q, u, a[u]);
		sum += a[u];
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
		last_u = u;
	}
	delete tmp;
	return sum;
}
PrimaDHeap::~PrimaDHeap()
{
	delete dh;
	a.clear();
	b.clear();
	vt.clear();
}