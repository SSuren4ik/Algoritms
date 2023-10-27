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

//int main()
//{
//	srand(time(NULL));
//	vector<vector<int>> arr = Generator(rand()%3+10);
//	WriteMatrixtoFile("input.txt", arr);
//
//	setlocale(LC_ALL, "Russian");
//
//	Graph graph;
//	graph.read("input.txt");
//	PrimaArray pra(graph);
//	PrimaDHeap prd(graph);
//	pra.execute(graph)->save("outputArrayPrima.txt");
//	prd.execute(graph)->save("outputDHeapPrima.txt");
//
// 	return 0;
//}
int main() 
{
    const int N_MAX = 4000 + 1;
    const int STEP = 100;
    const int Q = 1;
    const int R = 1000000;
    double result[200][2];

    PrimaArray primaArray;
    //PrimaDHeap primaDheap;

    for (int r = 1; r < 201; ++r)
    {
        int n = N_MAX; 
        int m = 1000 * n;
        Graph g = generate_random_graph(n, m, r, Q);
        clock_t tStart = clock();

        primaArray.execute(g);

        double end_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
        result[r - 1][0] = end_time;
        printf("n = %d, m = %d\n", n, m);
        printf("Time primaArray taken: %.2fs\n", end_time);
        printf("----------------\n");

        //tStart = clock();

        //primaDheap.execute(g);

        //end_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
        //result[r - 1][1] = end_time;
        //printf("n = %d, m = %d, r = %d\n", n, m, r);
        //printf("Time primaDheap taken: %.2fs\n", end_time);
        //printf("----------------\n");
    }

    std::ofstream file;
    file.open("results");
    if (file.is_open())
        for (auto& i : result)
            file << i[0] << " " << i[1] << std::endl;
    file.close();
    return 0;
}