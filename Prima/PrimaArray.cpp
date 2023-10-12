#include "PrimaArray.h"
using namespace std;

PrimaArray::PrimaArray(const Graph& graph)
{
	n = graph.get_node_count();
	a = new int[n];
	b = new int[n];
	vt = new bool[n];
}
Graph* PrimaArray::execute(Graph& graph)
{
	int mt = 0;
	Graph* graph1=new Graph(graph.get_node_count());
	int q;
	for (int i = 0; i < n; ++i)
	{
		vt[i] = 0;
	}
	int u = 0;
	vt[u] = 1;
	Link* tmp=graph.get_List()[0]->gethead()->next;
	//cout << "a  b" << endl;
	while(tmp!=nullptr)
	{
		a[tmp->src] = tmp->weight;
		b[tmp->src] = u;
		//cout << a[tmp->src] << " " << b[tmp->src] << endl;
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
		if (a[u] < 0)
		{
			throw exception();
		}
		q = b[u];
		vt[u] = 1;
		++mt;
		graph1->add_edge(q, u, a[u]);
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
	delete tmp;

	return graph1;
}
