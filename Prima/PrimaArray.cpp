#include "PrimaArray.h"
using namespace std;

int PrimaArray::execute(Graph& graph)
{
	n = graph.get_node_count();
	a.resize(n, INT_MAX);
	b.resize(n);
	vt.resize(n);
	int mt = 0;
	Graph graph1(n);
	int q;
	int u = 0;
	vt[u] = 1;
	int sum = 0;

	Link* tmp=graph.get_List()[0]->gethead()->next;
	while(tmp!=nullptr)
	{
		a[tmp->src] = tmp->weight;
		b[tmp->src] = u;
		tmp = tmp->next;
	}

	while (mt < n -1)
	{
		int min = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (vt[i] == 0 && a[i]!=0 && min > a[i])
			{
				min = a[i];
				u = i;
			}
		}
		if (a[u] ==INT_MAX)
		{
			return sum;
			throw exception("Граф несвязный");
		}
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
				a[tmp->src] = tmp->weight;
				b[tmp->src] = u;
			}
			tmp = tmp->next;
		}
	}
	return sum;
}

PrimaArray::~PrimaArray()
{
	a.clear();
	b.clear();
	vt.clear();
}