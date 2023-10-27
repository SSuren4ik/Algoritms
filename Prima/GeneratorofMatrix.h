#pragma once
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

//vector<vector<int>> Generator(int n)
//{
//	if (n <= 1)
//	{
//		throw exception("Корявая матрица");
//	}
//	vector<vector<int>> arr;
//	arr.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		arr[i].resize(n);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		for (int k = 0; k < i; ++k)
//		{
//			arr[i][k] = arr[k][i];
//		}
//		for (int k = i; k < n; ++k)
//		{
//			if (i == k)
//				arr[i][k] = 0;
//			else
//				arr[i][k] = rand() % 9+1;
//		}
//	}
//	return arr;
//}
//
//void WriteMatrixtoFile(string txt, vector<vector<int>>& arr)
//{
//	ofstream file;
//	if(!file.is_open())
//		file.open(txt);
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		for (int k = 0; k < arr.size(); ++k)
//		{
//			file << arr[i][k] << " ";
//		}
//		file << endl;
//	}
//	file.close();
//}

Graph generate_random_graph(int n, int m, int r, int q) {
	Graph graph (n);
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);
	uniform_int_distribution<int> uni(q, r);

	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dis(gen) <= m / ((double)n * (n - 1) / 2)) 
			{
				int random_weight = uni(rd);
				graph.add_edge(i, j, random_weight);
			}
		}
	}

	return graph;
}