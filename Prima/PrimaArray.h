#pragma once
#include "Graph.h"

using namespace std;

typedef pair<int, int> Pair;

class PrimaArray
{
private:
	int n;
	vector<int> a;
	vector<int> b;
	vector<bool> vt;
public:
	Graph* execute(Graph& graph);
	~PrimaArray();
};