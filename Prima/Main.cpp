#include <iostream>
#include "List.h"
#include "Graph.h"
#include "D-Heap.h"
#include "PrimaArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Graph graph;
	graph.read("input.txt");
	PrimaArray pr(graph);
	try
	{
		pr.execute(graph)->save("outputArrayPrima.txt");
	}
	catch (exception exp)
	{
		cout << "Граф несвязный";
		return 0;
	}
	return 0;
}