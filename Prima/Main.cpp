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
 	graph.save("output.txt");

	return 0;
}