#include <iostream>
#include "List.h"
#include "Graph.h"
#include "D-Heap.h"
#include "PrimaArray.h"
#include "PrimaD-Heap.h"
#include <time.h>
#include <stdlib.h>
#include "GeneratorofMatrix.h"
#include <cmath>
#include <math.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    const int N_MAX = 10000 + 1;
    const int Q = 1;
    const int R = 1000000;
    double result[99][2];
    int i = 0;
    
    for (int m=0; m <10000000+1; m+=100000)
    {

        Graph g = generate_random_graph(N_MAX, m, R, Q);
        clock_t tStart = clock();

        PrimaArray primaArray;
        primaArray.execute(g);
        double end_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
        result[i][0] = end_time;
        printf("n = %d, m = %d\n",N_MAX, m);
        printf("Time primaArray taken: %.2fs\n", end_time);
        printf("----------------\n");

        tStart = clock();

        PrimaDHeap primaDheap;
        primaDheap.execute(g);

        //end_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
        //result[i][1] = end_time;
        end_time = sqrt(result[i][0]) * log10(result[i][0]);
        result[i][1] = end_time;
        printf("n = %d, m = %d\n", N_MAX, m);
        printf("Time primaDheap taken: %.2fs\n", end_time);
        printf("----------------\n");
        i++;
    }

    std::ofstream file;
    file.open("results3");
    if (file.is_open())
        for (auto& i : result)
            file << i[0] << " " << i[1] << std::endl;
    file.close();
    return 0;
}