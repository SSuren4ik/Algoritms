#include <iostream>
#include "Graph.h"
#include "D-Heap.h"

using namespace std;

int main()
{
	Graph graph;
	setlocale(LC_ALL, "Russian");

	graph.read("input.txt");
	graph.save("output.txt");


	return 0;
}