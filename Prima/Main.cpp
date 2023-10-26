#include <iostream>
#include "List.h"
#include "Graph.h"
#include "D-Heap.h"
#include "PrimaArray.h"
#include "PrimaD-Heap.h"
#include <time.h>
#include <stdlib.h>
#include "GeneratorofMatrix.h"

using namespace std;

int main()
{
	srand(time(NULL));
	vector<vector<int>> arr = Generator(rand()%3+10);
	WriteMatrixtoFile("input.txt", arr);

	setlocale(LC_ALL, "Russian");

	Graph graph;
	graph.read("input.txt");
	PrimaArray pra(graph);
	PrimaDHeap prd(graph);
	pra.execute(graph)->save("outputArrayPrima.txt");
	prd.execute(graph)->save("outputDHeapPrima.txt");
	//try
	//{
	//}
	//catch (exception exp)
	//{
	//	cout <<exp.what();
	//	ofstream file("outputArrayPrima.txt");
	//	file << "Граф несвязный";
	//}
	//try
	//{
	//}
	//catch (exception exp)
	//{
	//	cout << exp.what();
	//	ofstream file("outputDHeapPrima.txt");
	//	file << "Граф несвязный";
	//}
 	return 0;
}