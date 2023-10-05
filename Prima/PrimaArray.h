#pragma once
#include "Graph.h"

using namespace std;

class PrimaArray
{
private:
	int n;
	int* a;
	int* b;
	bool* vt;
public:
	PrimaArray(const Graph& graph);
	Graph execute(const Graph& graph);
};